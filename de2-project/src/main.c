
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

int main (void){

// inicializace pinů a globálních proměnných
//int soil_humidity = get_soil_humidytiy();

//int tank_level = get_tank_level(); // in %
//int room_light = get_room_light(); 
//int lamp_intenzity = 0;
//bool pump_state = false;
//bool low_water_level = false; 
//bool bad_temp = false;

  // String for converting numbers by itoa()

    

    // UART
    uart_init(UART_BAUD_SELECT(9600, F_CPU));
    uart_puts("I2C sensor detected\r\n");
    sei();  // Needed for UART
      
    
    
    

    
    TIM1_OVF_1SEC
    TIM1_OVF_ENABLE

    sei();


while(1){
// tady bude všechna magie

          

  
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
air_humidity_int = get_air_humidity_int();
air_temp_int = get_air_temp_int();
air_humidity_dec = get_air_humidity_dec();
air_temp_dec = get_air_temp_dec();
uart_puts("Temperature: \r\n");
itoa(air_temp_int, string, 10);
uart_puts(string);
uart_puts(".");
itoa(air_temp_dec, string, 10);
uart_puts(string);
uart_puts(" °C\r\n");
uart_puts("Humidity: \r\n");
itoa(air_humidity_int, string, 10);
uart_puts(string);
uart_puts(".");
itoa(air_humidity_dec, string, 10);
uart_puts(string);
uart_puts(" %\r\n");

}