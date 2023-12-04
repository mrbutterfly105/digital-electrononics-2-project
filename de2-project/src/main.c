
// includes

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <uart.h>
#include <twi.h>
#include <dsiplay.h>
#include <stdlib.h>
// #include <font.h>
#include <buttons.h>

// end includes

// defines
#ifndef F_CPU
#define F_CPU 16000000
#endif

// end defines

// inicializace pinů a globálních proměnných

// int soil_humidity = get_soil_humidytiy();
// int air_humidity = get_air_humidity();
// int air_temp = get_air_temp();
// int tank_level = get_tank_level(); // in %
// int room_light = get_room_light();
// int16_t lamp_intenzity = 0;

// int8_t pump_state = 0;
// int8_t low_water_level = 0;
// int8_t bad_temp = 0;

int16_t max_temp = 30;
int16_t min_temp = 30;
int16_t min_tank_fill = 10; // in %

//! for debug
char stringtest[10];

int main(void)
{

    // inicialize knihoven
    twi_init();
    uart_init(UART_BAUD_SELECT(115200, F_CPU));

    init_display();
    init_buttons();

    sei();
    TIM2_OVF_16MS;
    TIM2_OVF_ENABLE;

    while (1)
    {
        ;
    }

    return 0;
}

static uint8_t j = 0;

void main_process()
{
    check_for_setup();
    update_display(j, j, j, j, j, j, &max_temp, &min_temp, &min_tank_fill);

    // test
    // uart_puts("\n");
    // itoa(max_temp, stringtest, 10);
    // uart_puts(stringtest);

    // itoa(min_temp, stringtest, 10);
    // uart_puts(stringtest);

    // itoa(min_tank_fill, stringtest, 10);
    // uart_puts(stringtest);
    // uart_puts("\n");
    // end test

    // test

    // uint8_t sw = read_switch();
    // char stringtest[2];
    // itoa(sw, stringtest, 10);
    // uart_puts(stringtest);
    // uart_puts("sw \n");

    // uint8_t clk = read_clk();
    // itoa(clk, stringtest, 10);
    // uart_puts(stringtest);
    // uart_puts(" clk \n");

    // end test
}

ISR(TIMER2_OVF_vect)
{

    // char stringtest[2];

    // itoa(get_button_state(LEFT), stringtest, 10);
    // uart_puts(stringtest);
    // uart_puts("\n");

    // itoa(get_button_state(RIGHT), stringtest, 10);
    // uart_puts(stringtest);
    // uart_puts("\n");

    // itoa(get_button_state(ENTER), stringtest, 10);
    // uart_puts(stringtest);
    // uart_puts("\n");

    //* refresh rate
    if (j == 10)
    {
        main_process();
        j = 0;
    }
    j++;
}