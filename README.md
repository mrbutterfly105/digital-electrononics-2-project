

# Smart plant watering system and data logger 

### Team members

* Tomáš Paulysko (responsible for display and encoder)
* Martin Mička (responsible for light sensor and lamp)
* Tomáš Husslik (responsible for soil moisture sensors and watering)
* Jakub Pachel(responsible for thermometer and humidity sensor, control lights)

## Theoretical description and explanation

Enter a description of the problem and how to solve it.

![Page5_2](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/5ac3bc4b-e355-40ce-aa90-88d9c50943ea)

## Hardware description of demo application

Insert descriptive text and schematic(s) of your implementation.

![Page6](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/a3395297-1f91-45a3-b652-0e4c7b957d01)

![Page7](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/images/SCHEMA.svg)

## Software description

Put flowchats of your algorithm(s) and direct links to source files in `src` or `lib` folders.

- dodělat:

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
   │
   │
   ├── src             // Source file(s)
   │   └── main.c
   ├── test            // No need this
   └── platformio.ini  // Project Configuration File
   ```

 * Knihovna `HumTempSensor.c` : [library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/soil/de2-project/lib/HumTempSensor/HumTempSensor.c) slouží ke čtení dat ze senzoru teploty vzduchu a vlhkosti vzduchu.
 Tato komunikace probíhá na principu I2C a proto je zde použita knihovna `twi`, kterou vytvořil pan doc. Ing. Tomáš Frýza, Ph.D a používali jsem jí v průběhu předmětu Digitální elektronika 2. Funkce `getDataFromSensor()` čte data z I2C z předem nadefinovaných adres a ukládá je do struktury `DHT_values_structure`. Celé a destinné části dat vlhkosti a teploty jsou uloženy jako bajty spolu s kontrolním součtem.
 Dále má tato knihovna funkce které vrácí tyto jednotlivé části:
 <br>
  - `get_air_humidity_int()`: Vrací celou část vzdušné vlhkosti.
  - `get_air_humidity_dec()`: Vrací desetinnou část vzdušné vlhkosti.
  - `get_air_temp_int()`: Vrací celou část vzdušné teploty.
  - `get_air_temp_dec()`: Vrací desetinnou část vzdušné teploty.
   <br>
    <br>

  Hlavičkový soubor  `HumTempSensor.h` : [header file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/main/de2-project/lib/HumTempSensor/HumTempSensor.h) slouží k deklaraci a definici funkcí aby následně kompilátor věděl jaké 

## Instructions

Write an instruction manual for your application, including photos and a link to a short app video.

## References

1. Write your text here.
2. ...
