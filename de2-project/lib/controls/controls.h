#ifndef controls_H
#define controls_H

#include <gpio.h>

// Definice pinů pro LED
#define LED_GREEN PD7  //pin D7 nastavení pinů ledek --> zelná je kontrolka pro nádrž vody
#define LED_RED PD6    //pin D6 nastavení pinů ledek --> červená je kontrolka pro vysokou teplotu

// Deklarace funkcí
void Low_water_LED(int Low_water_LED_State);
void bad_temp_LED(int bad_temp_LED_State);

#endif  