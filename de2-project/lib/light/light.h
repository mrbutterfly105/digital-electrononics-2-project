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

void light_init();
uint16_t get_ambient_light_state();
void set_rtc(int16_t hours, int16_t minutes, int16_t seconds);
void update_light(int8_t hours, int8_t minutes, int8_t seconds);
