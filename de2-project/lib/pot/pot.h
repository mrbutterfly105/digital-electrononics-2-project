/**
 * @file pot.h
 * @defgroup PotLibrary Pot Library <pot.h>
 * @code #include <pot.h> @endcode
 *
 * @brief Main control functions header file for the smart pot.
 *
 * The file defines functions and includes necessary headers for controlling the smart pot system.
 *
 * @{
 */
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


/**
 * @brief Updates the LED indicators based on system conditions.
 */
void update_led();

/**
 * @brief Main processing function for the smart pot, responsible for sensor updates,
 * LED control, and display updates.
 */
void main_process();

/**
 * @brief Initializes the smart pot, including peripherals and sensors.
 */
void pot_init();