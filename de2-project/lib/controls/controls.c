
#define LED_GREEN PB5  // nastavení pinů ledek --> zelná je kontrolka pro nádrž vody
#define LED_RED PB0    // nastavení pinů ledek --> červená je kontrolka pro vysokou teplotu
#include <gpio.h>     
int main(void)
{
int tank_level = 25;
int air_temp = 22.3;
uint16_t low_water_level = 0; 
uint16_t bad_temp = 0;
GPIO_mode_output(&DDRB, LED_GREEN);
GPIO_mode_output(&DDRB, LED_RED);

if (tank_level < 25){
   low_water_level = 1;
}else{
   low_water_level = 0;
}

if (air_temp < 10 || air_temp > 35){
   bad_temp = 1;
}else{
   bad_temp = 0;
}


if (low_water_level == 1){  
   GPIO_write_high(&DDRB, LED_GREEN);
}else{
   GPIO_write_low(&DDRB, LED_GREEN);

}

if(bad_temp == 1){
 GPIO_write_high(&DDRB, LED_RED);
}else{
   GPIO_write_low(&DDRB, LED_RED);
   
}

}