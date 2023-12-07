#include <pot.h>

#include "timer.h"

//! for debug
char string[10];
//! for debug

uint8_t j = 0;

int main(void)
{
    pot_init();
   
    sei();
    TIM1_OVF_262MS;
    TIM1_OVF_ENABLE;

    // TIM2_OVF_16MS;
    // TIM2_OVF_ENABLE;

    while (1)
    {
        // itoa(j, string, 10);
        // uart_puts(string);
        uart_puts(".");

        if (j > 1)
        {
            j = 0;
            main_process();
            uart_puts("j rst");
            uart_puts("\n");
        }
    }

    return 0;
}

ISR(TIMER1_OVF_vect)
{

    j++;
}
