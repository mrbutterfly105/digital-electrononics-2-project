/**
 * @file main.c
 * @brief Main program file for the smart pot system.
 */
#include <pot.h>

#include "timer.h"

//! for debug
char string[10];
//! for debug

uint8_t j = 0;
/**
 * @brief The main function for the smart pot system.
 * @details Initializes the system, enables global interrupts, sets up a timer interrupt,
 * and enters an infinite loop to continuously process the main logic.
 * @return The program exit code (always 0 in this case).
 */

int main(void)
{
    pot_init();

    sei();
    TIM1_OVF_262MS;
    TIM1_OVF_ENABLE;

    while (1)
    {
        uart_puts("");

        if (j > 1)
        {
            j = 0;
            main_process();
            uart_puts("main called \n");
            uart_puts("");
        }
    }

    return 0;
}
/**
 * @brief Timer1 overflow interrupt service routine.
 * @details Increments the variable 'j' to indicate the passage of time.
 */
ISR(TIMER1_OVF_vect)
{

    j++;
}
