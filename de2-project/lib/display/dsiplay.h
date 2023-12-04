#ifndef DISPLAY_H
#define DISPLAY_H

#include <oled.h>
#include <uart.h>
#include <buttons.h>

// Definice adresy displeje (případně doplňte správnou hodnotu)
#define DISPLAY_ADDR 0x00

// Funkce pro inicializaci displeje
void init_display();
void check_for_setup();
void update_display(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill, 
                    int16_t* max_temp, int16_t* min_temp, int16_t* min_tank);
void adjust(int16_t *value);
void set_default();
void print_setup_max_temp();
void print_setup_min_temp();
void print_setup_min_tank_fill();
void print_default(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill);

#endif // DISPLAY_H
