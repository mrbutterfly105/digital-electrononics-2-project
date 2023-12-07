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


void update_led();
void main_process();
void pot_init();