/**
 * @file light.h
 * @defgroup Lamp Library <light.h>
 * @code #include <light.h> @endcode
 *
 * @brief Light System Library.
 *
 *
 * @{
 */


/***********************************************************************
 * 
 * Light library for functions regarding light and lamp.
 *
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/
// light_control.h

#define LIGHT_CONTROL_H

#include <stdint.h>

#define SENZOR_PIN PC1 // A1
#define LAMP PB2       // D10

/**
 * @brief Initialize the light system
 */
void light_init();

/**
 * @brief Get the light state from the sensor
 * @return The light state
 */
uint16_t get_ambient_light_state();

/**
 * @brief Set the real-time clock (RTC) time
 * @param hours The hours value
 * @param minutes The minutes value
 * @param seconds The seconds value
 */
void set_rtc(int16_t hours, int16_t minutes, int16_t seconds);


void update_light();
