/***********************************************************************
 * 
 * Soil library for capacitive soil moisture sensor (v1.2) + pump functions. 
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/**
 * @file 
 * @defgroup Soil library <soil.h>
 * @code #include <soil.h> @endcode
 *
 * @brief Soil library for smart watering system.
 *
 * The library contains functions for reading analog values using the ADC at pins ADC0 and ADC1. Two more functions controll digital output of pin PB0.
 *
 * @{
 */

/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Get tank fullness percentage. 
 * @return uint8_t percentage value, maximum level - 100%, minimum - 0%
 */
uint8_t getTankLevelPercentage();

/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Get soil moisture percentage. 
 * @return uint8_t percentage value, maximum moisture - 100%, minimum - 0%
 */
uint8_t getSoilHumidityPercentage();

/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Set pin PB0 to logical 1.
 * @return none
 */
void pumpTurnOff();

/* Function prototypes -----------------------------------------------*/
/**
 * @brief  Set pin PB0 to logical 0.
 * @return none
 */
void pumpTurnOn();
