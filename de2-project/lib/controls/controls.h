/**
 * @file controls.h 
 * @defgroup Controls - temperature and fulness of tank <controls.h>
 * @code #include <controls.h> @endcode
 *
 * @brief Control functions for maintaining good temperature and tank fullness.
 *
 * This module provides functions to control LEDs indicating low water level and high temperature.
 *
 * @{
 */

#ifndef controls_H
#define controls_H

#include <gpio.h>

// Definice pinů pro LED
#define LED_GREEN PD7  //pin D7 nastavení pinů ledek --> zelná je kontrolka pro nádrž vody
#define LED_RED PD6    //pin D6 nastavení pinů ledek --> červená je kontrolka pro vysokou teplotu

/**
 * @brief Controls the LED for low water level.
 * 
 * This function sets the state of the LED to indicate a low water level.
 * 
 * @param Low_water_LED_State State of the LED for low water level (1 = on, 0 = off).
 * @return None.
 */
void Low_water_LED(int Low_water_LED_State);

/**
 * @brief Controls the LED for high temperature.
 * 
 * This function sets the state of the LED to indicate high temperature.
 * 
 * @param bad_temp_LED_State State of the LED for high temperature (1 = on, 0 = off).
 * @return None.
 */
void bad_temp_LED(int bad_temp_LED_State);

#endif