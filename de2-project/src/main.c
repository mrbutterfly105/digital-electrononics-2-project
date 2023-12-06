
#ifndef F_CPU
# define F_CPU 16000000  // CPU frequency in Hz required for UART_BAUD_SELECT
#endif


/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <twi.h>            // I2C/TWI library for AVR-GCC
#include <uart.h>           // Peter Fleury's UART library
#include <stdlib.h>         // C library. Needed for number conversions
#include <HumTempSensor.h>
#include <controls.h>

int main (void){

// inicializace pinů a globálních proměnných
//int soil_humidity = get_soil_humidytiy();


//int room_light = get_room_light(); 
//int lamp_intenzity = 0;
//bool pump_state = false;


  // String for converting numbers by itoa()

    

    // UART
    // uart_init(UART_BAUD_SELECT(9600, F_CPU));
    // uart_puts("I2C sensor detected\r\n");
    //sei();  // Needed for UART
      
    
    
    

    
    // TIM1_OVF_1SEC
    // TIM1_OVF_ENABLE

    // sei();


while(1){
// tady bude všechna magie

     ;     

  
}


return 0;
}

ISR(TIMER1_OVF_vect)
{

char string[2]; 
float air_humidity_int;
float air_temp_int;
float air_humidity_dec;
float air_temp_dec;
air_humidity_int  = get_air_humidity_int();
air_temp_int = get_air_temp_int();
air_humidity_dec = get_air_humidity_dec();
air_temp_dec = get_air_temp_dec();



uint16_t tank_level =getTankLevelPercentage();
//int low_water_level = 0; 
//int bad_temp = 0;
uint16_t air_temp = air_temp_int + air_temp_dec/10;

if (tank_level < 25){
   Low_water_LED(1);
}else{
   Low_water_LED(0);
}

if (air_temp < 10 || air_temp > 35){
   bad_temp_LED(1);
}else{
   bad_temp_LED(0);
}

}