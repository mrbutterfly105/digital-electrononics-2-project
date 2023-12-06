/***********************************************************************
 * 
 * controls library for AVR-GCC.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2023 Jakub Pachel
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/


#define LED_GREEN PD7  //pin D7 nastavení pinů ledek --> zelná je kontrolka pro nádrž vody
#define LED_RED PD6    //pin D6 nastavení pinů ledek --> červená je kontrolka pro vysokou teplotu
#include <gpio.h>   
//#include <uart.h>    
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC


  

void Low_water_LED(int Low_watter_LED_State) {
   GPIO_mode_output(&DDRD, LED_GREEN); // Nastaví pin LED jako výstup
   // sei();  // Povolí globální přerušení (Potřebné pro UART)
    if (Low_watter_LED_State == 1) {
      //uart_puts("R1 \r\n"); // Pošle zprávu oznamující, že červená LED je zapnuta
      GPIO_write_high(&PORTD, LED_GREEN);  // Zapne červenou LED
    } else if (Low_watter_LED_State == 0) {
       //uart_puts("R0 \r\n"); // Pošle zprávu oznamující, že červená LED je vypnuta
      GPIO_write_low(&PORTD, LED_GREEN); // Vypne červenou LED
    } 
}


void bad_temp_LED(int bad_temp_LED_State) {
   GPIO_mode_output(&DDRD, LED_RED); // Nastavení pin LED jako výstup
    //sei();  // Povolí globální přerušení (Potřebné pro UART)
    if (bad_temp_LED_State == 1) {
       //uart_puts("G1 \r\n"); // Pošle zprávu oznamující, že zelená LED je zapnuta
     GPIO_write_high(&PORTD, LED_RED); // Zapne zelenou LED
    } else if (bad_temp_LED_State == 0) {
       //uart_puts("G0 \r\n"); // Pošle zprávu oznamující, že zelená LED je vypnuta
       GPIO_write_low(&PORTD, LED_RED); // Vypne zelenou LED
    }
}