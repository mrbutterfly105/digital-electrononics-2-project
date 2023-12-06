

# Smart plant watering system and data logger 

### Team members

* Tomáš Paulysko (responsible for display and encoder)
* Martin Mička (responsible for light sensor and lamp)
* Tomáš Husslik (responsible for soil moisture sensors and watering)
* Jakub Pachel(responsible for thermometer and humidity sinsor, control lights)

## Theoretical description and explanation

Enter a description of the problem and how to solve it.

![Page5_2](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/5ac3bc4b-e355-40ce-aa90-88d9c50943ea)

## Hardware description of demo application

Insert descriptive text and schematic(s) of your implementation.

![Page6](https://github.com/mrbutterfly105/digital-electrononics-2-project/assets/61315339/a3395297-1f91-45a3-b652-0e4c7b957d01)


## Software description

Put flowchats of your algorithm(s) and direct links to source files in `src` or `lib` folders.

 * Knihovna `HumTempSensor.c` : [library source file](https://github.com/mrbutterfly105/digital-electrononics-2-project/blob/soil/de2-project/lib/HumTempSensor/HumTempSensor.c) slouží ke čtení dad ze senzoru teploty vzduchu a vlhkosti vzduchu.
 Tato kominikace probíhá na principu I2C a proto je zde použita knihovna `twi`, kterou vytvořil pan doc. Ing. Tomáš Frýza, Ph.D a používali jsem jí v průběhu předmětu Digitální elektronika 2. Funkce `getDataFromSensor()` čte data z I2C z předem nadefinovaných adres.

## Instructions

Write an instruction manual for your application, including photos and a link to a short app video.

## References

1. Write your text here.
2. ...
