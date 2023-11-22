
// includes

#include "timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <uart.h>
#include <twi.h>
#include <dsiplay.h>
#include <stdlib.h>
#include <font.h>


// end includes

// defines
#ifndef F_CPU
#define F_CPU 16000000
#endif
// end defines

int main (void){

// inicialize knihoven
twi_init();
uart_init(UART_BAUD_SELECT(115200,F_CPU));
init_display();

sei();
TIM2_OVF_16MS;
TIM2_OVF_ENABLE;

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


while(1){
;
  
}


return 0;
}


void main_process(){
//all the magic
update_displa(10, 10, 10, 10);

}


ISR(TIM2_OVF_vect){
uart_puts("nevim ne");
main_process();

}