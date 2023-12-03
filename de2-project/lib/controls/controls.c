
#define LED_GREEN PD7  //pin D7 nastavení pinů ledek --> zelná je kontrolka pro nádrž vody
#define LED_RED PD6    //pin D6 nastavení pinů ledek --> červená je kontrolka pro vysokou teplotu
#include <gpio.h>   
#include <uart.h>    
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC


  

void Low_water_LED(int Low_watter_LED_State) {
   GPIO_mode_output(&DDRB, LED_GREEN);
    sei();  // Needed for UART
    if (Low_watter_LED_State == 1) {
      uart_puts("R1 \r\n");
      GPIO_write_high(&PIND, LED_GREEN);  
    } else if (Low_watter_LED_State == 0) {
       uart_puts("R0 \r\n");
      GPIO_write_low(&PIND, LED_GREEN);
    } 
}

void bad_temp_LED(int bad_temp_LED_State) {
   GPIO_mode_output(&DDRB, LED_RED);
    sei();  // Needed for UART
    if (bad_temp_LED_State == 1) {
       uart_puts("G1 \r\n");
     GPIO_write_high(&PIND, LED_RED);
    } else if (bad_temp_LED_State == 0) {
       uart_puts("G0 \r\n");
       GPIO_write_low(&PIND, LED_RED);
    }
}