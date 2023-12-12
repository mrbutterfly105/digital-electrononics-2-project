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

ISR(TIMER1_OVF_vect)
{

    j++;
}
