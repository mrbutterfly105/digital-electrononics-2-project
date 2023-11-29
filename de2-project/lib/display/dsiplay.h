#ifndef DISPLAY_H
#define DISPLAY_H

#include <oled.h>
#include <uart.h>

// Definice adresy displeje (případně doplňte správnou hodnotu)
#define DISPLAY_ADDR 0x00

// Funkce pro inicializaci displeje
void init_display();

// Funkce pro zobrazení hodnot na displeji
void update_display(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill);

#endif // DISPLAY_H
