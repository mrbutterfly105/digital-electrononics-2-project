

# Chytrý systém pro zavlažování rostlin se záznamníkem dat

Tenhle projekt je zakončující projekt předmětu [Digitální elektronika 2](https://github.com/tomas-fryza/digital-electronics-2/tree/master/labs/09-project) na VUT v Brně.

### Autoři

* Tomáš Paulysko (responsible for display and encoder)
* Martin Mička (responsible for light sensor and lamp)
* Tomáš Husslik (responsible for soil moisture sensors and watering)
* Jakub Pachel(responsible for thermometer and humidity sensor, control lights)

## Teoretický popis a vysvětlení

Enter a description of the problem and how to solve it:

Tento projekt se zabývá automatizovaným procesem pečování o rostlinu. Péče o rostlinu dokáže být velice obtížná činnost. Někdo to má jako koníček ale zdaleka né každého baví zaždodení zalévání a sledování počasí aby jim jejich rostlina například nezmrzla. Proto náš tým vytvořil tento projek díky němuž pěstování kytek nebylo nikdy jednodušší. Stačí doplňovat nádrž na vodu na což vás sama upozorní kontrolka kterou má náš produkt v sobě zabudovaný. Druhá kontrolka vás upozorní pokud jsou pro rostlinu nepříznivé teplotní podmínky. Rozsah teplotních podmínek pro jednotlivé kytky a hranice plnosti nádrže při které chcte aby vás produkt upozornil na nutnost doplnění jsou také individuální. Proto je náš produkt doplněn o displej na kterém se přehledně zobrazují hodnoty z čidel ale hlavně díky 3 tlačítkům si můžete nastavit prahy maximální a minimální teploty a zároveň si můžete nastavit procentuální hranici objemu nádrže při které se rozsvítí kontrolka. Nastavování pomocí tlačítek je velice intuitivní a ovládání je popsáno v sekci návod (instructions)

<!---
![Page5_2](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/5ac3bc4b-e355-40ce-aa90-88d9c50943ea))
-->
## Hardwarový popis

Insert descriptive text and schematic(s) of your implementation.

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
  - Na pumpování vody z nádrže do květináče používáme `relé (doplnit jaký)`.
  - k ovládání používáme 3 tlačítka `tlačítka`.
  - pro zobrazování hodnot používáme `oled display`.

<!---
![Page6](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/a3395297-1f91-45a3-b652-0e4c7b957d01)
-->
Na obrázku je znázorněno jakým způsobem jsou jednotlivé součástky připojené k Arduinu.
![Page7](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/images/zapojení.svg)



![realizace](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/24e787b6-26b1-4c22-89d5-f894bc44e786)

## Softwarový popis

Doxygen dokumentace dostupná ne: [Smart pot documentation](https://mrbutterfly105.github.io/digital-electrononics-2-project/).

Put flowchats of your algorithm(s) and direct links to source files in `src` or `lib` folders.

![Page7](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/images/Diagramf.png)


Struktura projektu vypadá následovně.

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
   <br>
* V hlavičkovém souboru  `HumTempSensor.h` : [header file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/HumTempSensor/HumTempSensor.h) jsou pak tyto funkce deklarovány.

### Rozsvěcování kontrolek malého obsahu nádrže a špatné teploty
* Knihovna `controls.c` : [library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/controls/controls.c) Podle stavu rozsvěcí a zhasíná jednotlivé jednotlivé kontrolky. Stav se přiřazuje v knihovně `pot.c` :[library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project//lib/pot/pot.c).

### Čtení ze senzoru na světlo
 * Knihovna `light.c` : [Library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/light/light.c) slouží k ke čtení ze senzoru zda se nachází v okolním prostředí dostatek světla. Tento senzor je zapojen pomocí pararelního zapojení fotorezistoru a 2k odporu. Ze senzoru dostáváme dvě hodnoty 1 nebo 0, tedy pokud se v okolí nachází světlo nebo nikoliv. Při nedostatku světla se lampa zapne, v našem provedení jde o modrou LED diodu.
 * V hlavičkovém souboru `light.h` : [header file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/light/light.h) jsou použité funkce deklarovány. 
## Instrukce

Write an instruction manual for your application, including photos and a link to a short app video.

## Zdroje

1. Learning material from Digital electronics 2 course.
2. Libraries from [Digital-Electronics-2](https://github.com/tomas-fryza/digital-electronics-2) GitHub repository created by doc. Ing. Tomáš Frýza Ph.D.
3. Arduino Uno board [documentation](https://docs.arduino.cc/hardware/uno-rev3)
