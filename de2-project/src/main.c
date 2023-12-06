
/* Includes ----------------------------------------------------------*/
#include <HumTempSensor.h>
#include <controls.h>
#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <uart.h>
#include <twi.h>
#include <dsiplay.h>
#include <stdlib.h>
// #include <font.h>
#include <buttons.h>
#include <rtc.h>
#include <soil.h>
#include <stdio.h>
#include <light.h>

// end includes

// defines

#ifndef F_CPU
#define F_CPU 16000000
#endif

// int soil_humidity = get_soil_humidytiy();
int air_humidity_int = 0;
int air_humidity_dec = 0;
int air_temp_int = 0;
int air_temp_dec = 0;

int soil_hum = 0;
int tank_level = 0;

// int room_light = get_room_light();
// int16_t lamp_intenzity = 0;

// int8_t pump_state = 0;
// int8_t low_water_level = 0;
// int8_t bad_temp = 0;

int16_t max_temp = 30;      // in C
int16_t min_temp = 10;      // in C
int16_t min_tank_fill = 10; // in %

uint16_t hours = 6;
uint16_t minutes = 59;
uint16_t seconds = 30;

//! for debug
char string[10];
//! for debug

uint8_t j = 0;

int main(void)
{

    // inicialize knihoven
    twi_init();
    uart_init(UART_BAUD_SELECT(115200, F_CPU));

    init_display();
    init_buttons();
    // rtc_init();
    // set_rtc(hours, minutes, seconds);
    // light_init();

    // air_humidity_int = get_air_humidity_int();
    // air_humidity_dec = get_air_humidity_dec();
    // air_temp_int = get_air_temp_int();
    // air_temp_dec = get_air_temp_dec();

    // soil_hum = getSoilHumidityPercentage();
    // tank_level = getTankLevelPercentage();

    sei();
    TIM1_OVF_33MS;
    TIM1_OVF_ENABLE;

    TIM2_OVF_16MS;
    TIM2_OVF_ENABLE;

    while (1)
    {
        main_process();
        delay();

    }

    return 0;
}

void update_led()
{
    uint16_t air_temp = air_temp_int + air_temp_dec / 10;
    if (tank_level < min_tank_fill)
    {
        Low_water_LED(1);
    }
    else
    {
        Low_water_LED(0);
    }
    if (air_temp < min_temp || air_temp > max_temp)
    {
        bad_temp_LED(1);
    }
    else
    {
        bad_temp_LED(0);
    }
}

void main_process()
{

    // air_humidity_int = get_air_humidity_int();

    // air_humidity_dec = get_air_humidity_dec();

    // air_temp_int = get_air_temp_int();

    // air_temp_dec = get_air_temp_dec();

    // update_led();

    // update_light(hours, minutes, seconds);

    // // debug
    // itoa(hours, string, 10);
    // uart_puts(string);
    // // debug

    // rtc_read_hours(&hours);

    // itoa(hours, string, 10);
    // uart_puts(string);
    // // debug

    // rtc_read_minutes(&minutes);
    // rtc_read_seconds(&seconds);
    check_for_setup();
    uart_puts("nevim");
    update_display(air_temp_int, air_temp_dec, air_humidity_int,
                   air_humidity_dec, soil_hum, tank_level,
                   &max_temp, &min_temp, &min_tank_fill);
}

// ISR(TIMER1_OVF_vect)
// {
//     main_process();
// }

// // display timer
// ISR(TIMER2_OVF_vect)
// {

//     if (j == 10)
//     {

//         j = 0;
//     }
//     j++;
// }
