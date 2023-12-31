

# Chytrý systém pro zavlažování rostlin se záznamníkem dat

Tenhle projekt je zakončující projekt předmětu [Digitální elektronika 2](https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/09-project) na VUT v Brně.

### Autoři

* Tomáš Paulysko (zodpovědný za tlačítka, oled displej, hlavní proces a video)
* Martin Mička (zodpovědný za senzor světla, lampu, vývojový diagram a README)
* Tomáš Husslik (zodpovědný za senzor vlhkosti hlíny a hladiny nádrže, zalévání a README)
* Jakub Pachel((zodpovědný za senzor vlhkosti a teploty vzduchu, kontrolky, doxygen generování a README)

## Teoretický popis a vysvětlení

<!---
Nevím co přesně mělo být zde tak jsem se ten produkt pokusil trochu prodat
-->


Tento projekt se zabývá automatizovaným procesem pečování o rostlinu. Péče o rostlinu dokáže být velice obtížná činnost. Někdo to má jako koníček ale zdaleka né každého baví každodení zalévání a sledování počasí aby jim jejich rostlina například nezmrzla. Proto náš tým vytvořil tento projekt díky němuž pěstování kytek nebylo nikdy jednodušší. Stačí doplňovat nádrž na vodu na což vás sama upozorní kontrolka kterou má náš produkt v sobě zabudovaný. Druhá kontrolka vás upozorní pokud jsou pro rostlinu nepříznivé teplotní podmínky. Rozsah teplotních podmínek pro jednotlivé kytky a hranice plnosti nádrže při které chcte aby vás produkt upozornil na nutnost doplnění jsou také individuální. Proto je náš produkt doplněn o displej na kterém se přehledně zobrazují hodnoty z čidel ale hlavně díky 3 tlačítkům si můžete nastavit prahy maximální a minimální teploty a zároveň si můžete nastavit procentuální hranici objemu nádrže při které se rozsvítí kontrolka. Nastavování pomocí tlačítek je velice intuitivní a ovládání je popsáno v sekci návod (instrukce). Dostatek vody a správná teplota není to jediné co kytky potřebují proto je náš produkt obohacen o senzor světla díky němuž produkt dokáže vyhodnotit kdy jsou špatné světelné podmínky a rozsvítí lampu.

<!---
![Page5_2](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/5ac3bc4b-e355-40ce-aa90-88d9c50943ea))
-->
## Hardwarový popis
<!---
Insert descriptive text and schematic(s) of your implementation.
-->
<!---
TADY TOPSAT TYPY SOUČÁSTEK (PŘÍPADNĚ UPRAVIT)
-->
Hardware našeho projektu:
  - ovládací jednotka `Arduino UNO` od společnosti `Atmel`.
  - Dva senzory vlhkosti kdy jeden z nich měří vlhkost hlíny v květináči a ten druhý měří obsah nádrže na vodu. Pro obě měření využíváme senzor: `Capacitive soil moisture sensor v1.2` 
  - Jako další senzor využíváme senzor teploty a vlhkosti vzduchu: `DHT12` který s arduinem kominikuje skrz I2C.
  - Jako senzor okolního světla využíváme `fotorezistor GL5539`.
  - Lampa která se rozsvěcí v závislosti na dostatek světla je v našem provedení `modrá led dioda`.
  - Kontrolka která se rozsvítí při nepříznivých teplotních podmínkách `červená led dioda`.
  - Kontrolka která se rozsvítí při malém objemu nádrže na vodu `zelená led dioda`.
  - Na pumpování vody z nádrže do květináče používáme `Jednokanálový relé modul - 5V`.
  - k ovládání používáme 3 tlačítka `tlačítka`.
  - pro zobrazování hodnot používáme `I2C OLED display 128x64`.

<!---
![Page6](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/a3395297-1f91-45a3-b652-0e4c7b957d01)
-->
Na obrázku je znázorněno jakým způsobem jsou jednotlivé součástky připojené k Arduinu. I2C komunikaci využívá oled displej a senzor teploty a vlhkosti vzduchu. Dále náš produkt využívá 7 digitálních pinů a 3 analogové.

![Page7](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/images/Zapojen%C3%AD.svg)


Takto vypadá zapojení pro demonstraci funkčnosti na hodině digitální elektroniky 2. Následující obrázek vznikl na začátku realizace projektu. V průběhu vyvýjení projektu se naše představy jak by výsledná realizace měla vypadat nezměnili. A proto si návrh jak by naše finální realizace vypadala můžete prohlédnout zde:



![realizace](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/24e787b6-26b1-4c22-89d5-f894bc44e786)

## Softwarový popis


##### Doxygen dokumentace dostupná na: [Smart pot documentation](https://mrbutterfly105.github.io/digital-electrononics-2-project/).


Pro lepší orientaci v tom jak kód funguje byl vytvořen vývojový diagram. Který zobrazuje jednotlivé rozhodovací procesy programu: 


![Page7](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/images/Diagramf.png)


Jelikož náš kód obsahuje spoustu knihoven a jejich hlavičkových souborů. Pro lepší přehled je zde znázorněna struktura co za soubory náš program obsahuje.

```c
   DE2-PROJECT          
   ├── include         // Included file(s)
   │   └── timer.h
   ├── lib             // Libraries
   │   ├── gpio        // Your GPIO library
   │   │   ├── gpio.c
   │   │   └── gpio.h
   │   ├── oled        
   │   │   ├── oled.c
   │   │   ├── oled.h
   │   │   └── font.h
   │   ├── uart       
   │   │   ├── uart.c
   │   │   └── uart.h
   │   ├── twi       
   │   │   ├── twi.c
   │   │   └── twi.h
   │   ├── soil       
   │   │   ├── soil.c
   │   │   └── soil.h
   │   ├── controls       
   │   │   ├── controls.c
   │   │   └── controls.
   │   ├── HumTempSensor       
   │   │   ├── HumTempSensor.c
   │   │   └── HumTempSensor.h
   │   ├── rtc       
   │   │   ├── rtc.c
   │   │   └── rtc.h
   │   ├── display       
   │   │   ├── display.c
   │   │   └── display.h
   │   ├── buttons       
   │   │   ├── buttons.c
   │   │   └── buttons.h
   │   ├── pot       
   │   │   ├── pot.c
   │   │   └── pot.h
   │   └── light       
   │       ├── light.c
   │       └── light.h
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   └── platformio.ini  // Project Configuration File
   ```
<!---
Tohle jsem z toho vytáhl jelikož to již nepoužíváme
 │   ├── rtc        
 │   │   ├── rtc.c
 │   │   └── rtc.h
 -->
### čtení ze senzoru vlhkosti a teploty vzduchu
 * Knihovna `HumTempSensor.c` : [library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/soil/de2-project/lib/HumTempSensor/HumTempSensor.c) slouží ke čtení dat ze senzoru teploty vzduchu a vlhkosti vzduchu.
 Tato komunikace probíhá na principu I2C a proto je zde použita knihovna `twi`, kterou vytvořil pan doc. Ing. Tomáš Frýza, Ph.D a používali jsem jí v průběhu předmětu Digitální elektronika 2. Funkce `getDataFromSensor()` čte data z I2C z předem nadefinovaných adres a ukládá je do struktury `DHT_values_structure`. Celé a destinné části dat vlhkosti a teploty jsou uloženy jako bajty spolu s kontrolním součtem.
 Dále má tato knihovna funkce které vrácí tyto jednotlivé části:

   - `get_air_humidity_int()`: Vrací celou část vzdušné vlhkosti.
   - `get_air_humidity_dec()`: Vrací desetinnou část vzdušné vlhkosti.
   - `get_air_temp_int()`: Vrací celou část vzdušné teploty.
   - `get_air_temp_dec()`: Vrací desetinnou část vzdušné teploty.
  
 * V hlavičkovém souboru  `HumTempSensor.h` : [header file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/HumTempSensor/HumTempSensor.h) jsou pak tyto funkce deklarovány.

### Rozsvěcování kontrolek malého obsahu nádrže a špatné teploty
 * Knihovna `controls.c` : [library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/controls/controls.c) Podle stavu rozsvěcí a zhasíná jednotlivé jednotlivé kontrolky. Stav se přiřazuje v knihovně `pot.c` : [library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project//lib/pot/pot.c).

### Čtení ze senzoru na světlo
 * Knihovna `light.c` : [Library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/light/light.c) slouží k ke čtení ze senzoru zda se nachází v okolním prostředí dostatek světla. Tento senzor je zapojen pomocí pararelního zapojení fotorezistoru a 2k odporu. Ze senzoru dostáváme dvě hodnoty 1 nebo 0, tedy pokud se v okolí nachází světlo nebo nikoliv. Při nedostatku světla se lampa zapne, v našem provedení jde o modrou LED diodu.
 * V hlavičkovém souboru `light.h` : [header file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/light/light.h) jsou použité funkce deklarovány.
### Čtení ze senzorů vlhkosti
 * Knihovna `soil.c` : [Library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/soil/soil.c) zajišťuje převod analogové hodnoty na senzoru na digitální hodnotu. Obsahuje dvě funkce, které používají piny ADC0 pro senzor půdy, respektive ADC1 pro senzor vody v nádrži. Převod ADC je realizován tzv. polling způsobem. Tyto funkce vrací procentuální hodnotu vlhkosti půdy, případně hladiny v nádrži. Funkce byly zkalibrovány podle použitých senzorů. V knihovně se navíc nachází dvě funkce pro ovládání relé (pumpa), které je ovládáno pomocí digitálního pinu PB0. Relé je active low, funkce toto zohledňují. 
 * Hlavičkový soubor `soil.h` : [header file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/soil/soil.h) obsahuje deklarace funkcí.
### Knivna pot.c, display a tlačítka


* Knihova `pot.c` : [Library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/pot/pot.c) je knihovna která se stará o celý chod programu. Obsahuje dvě hlavní funkce `main_process()`[](), ve které běží celá logika programu. Druhá hlavní funkce je `pot_init()`[]() ve které se inicializují všechny ostatní knihovny. 
* Knihvna `display.c` : [Library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/display/display.c) obsahuje všehny funkce pro obsluhu displeje a pro zobrazování jednotlivých obrazocek menu. Zárověň Komunikuje s knihovnou `buttons.c` pro detekci tlačítek.
* Knihvna `buttons.c` : [Library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/buttons/buttons.c) obsahuje funkce pro detekci a inicializaci tlačítek.


## Instrukce
Po zapojení všech součástek k arduinu a nahrání kódu, se na oled displeji objeví hlavní menu, na kterém jsou vypsané údaje o teplotě a vlhkosti vzduchu, o vlhkosti půdy a o množství vody v nádrži. Po prvním zmáčknutí bílého tlačítka se na displeji z menu dostaneme na nastavení maximální povolené teploty. Tuto teplotu můžeme změnit pomocí červeného a černého tlačítka, při zmáčknutí červeného tlačítka se teplota sníží, naopak při zmáčknutí černého tlačítka se teplota zvýší. Tímto způsobem si nastavíme požadovanou maximální teplotu vzduchu. Při dalším zmáčknutí bílého tlačítka se dostaneme na nastavení minimální možné teploty, kterou nastavíme stejně za použití tlačítek. Pokud teplota ze senzoru nebude v rozmezí rozsvítí se červená kontrolka.
Při dalším prokliku bílého tlačítka se dostaneme do nastavení, ve kterém nastavíme při jaké plnosti nádrže na vodu začne svítit zelená kontrolka, která značí málo vody v nádrži.
Po dalším zmáčknutí bílého tlačítka se dostáváme zpátky do menu. 
Toto jsou jediné věci, které uživatel sám nastaví, jinak vše běží automaticky.

![Page7](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/images/Foto%20zapojení.jpg)
<!---
<a href="https://www.youtube.com/watch?v=wBUNLNUlrbI"><h3>Video návod</h3></a>
-->
### [Video návod](https://www.youtube.com/watch?v=wBUNLNUlrbI)

## Zdroje

1. Learning material from Digital electronics 2 course.
2. Libraries from [Digital-Electronics-2](https://github.com/tomas-fryza/digital-electronics-2) GitHub repository created by doc. Ing. Tomáš Frýza Ph.D.
3. Arduino Uno board [documentation](https://docs.arduino.cc/hardware/uno-rev3)
4. [Basic syntax](https://www.markdownguide.org/basic-syntax/?fbclid=IwAR3edqHBhttWhvDszvdMqhuNkEclzyDmhEbuplxvEvYDWxaCE9yKuwSAkz0) for GitHub documentation.
