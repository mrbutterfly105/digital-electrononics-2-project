/**
 * @file pot.c
 * @brief Main control functions implementation file for the smart pot.
 */

/* Includes ----------------------------------------------------------*/
#include <controls.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <twi.h>
#include <uart.h>

#include <HumTempSensor.h>
#include <dsiplay.h>
#include <buttons.h>
#include <rtc.h>
#include <soil.h>
#include <light.h>

// end includes

// defines
#ifndef F_CPU
#define F_CPU 16000000 // CPU frequency in Hz required for UART_BAUD_SELECT
#endif

int air_humidity_int = 0;
int air_humidity_dec = 0;
int air_temp_int = 0;
int air_temp_dec = 0;

int soil_hum = 0;
int tank_level = 0;

int16_t max_temp = 30;      // in C
int16_t min_temp = 10;      // in C
int16_t min_tank_fill = 40; // in %

//! for debug
char string[10];
//! for debug

/**
 * @brief Updates the LED indicators based on system conditions.
 */
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


/**
 * @brief Placeholder for the pump update function.
 */

    

void update_pump()
{
    if (soil_hum < 30 && tank_level > 10)
    {
        pumpTurnOn();
    }
    else
    {
        pumpTurnOff();
    }
}

/**
 * @brief Initializes the smart pot, including peripherals and sensors.
 */
void pot_init()
{

    twi_init();
    uart_init(UART_BAUD_SELECT(115200, F_CPU));

    init_display();
    init_buttons();

    // rtc_init();
    // set_rtc(hours, minutes, seconds);
    light_init();

    air_humidity_int = get_air_humidity_int();
    air_humidity_dec = get_air_humidity_dec();
    air_temp_int = get_air_temp_int();
    air_temp_dec = get_air_temp_dec();

    soil_hum = getSoilHumidityPercentage();
    tank_level = getTankLevelPercentage();
}

/**
 * @brief Main processing function for the smart pot, responsible for sensor updates,
 * LED control, and display updates.
 */
void main_process()
{
    air_humidity_int = get_air_humidity_int();
    air_humidity_dec = get_air_humidity_dec();
    air_temp_int = get_air_temp_int();
    air_temp_dec = get_air_temp_dec();

    soil_hum = getSoilHumidityPercentage();
    tank_level = getTankLevelPercentage();

    update_led();
    update_pump();

    update_light();

    check_for_setup();
    update_display(air_temp_int, air_temp_dec, air_humidity_int,
                   air_humidity_dec, soil_hum, tank_level,
                   &max_temp, &min_temp, &min_tank_fill);
}
