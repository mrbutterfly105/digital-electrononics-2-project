#ifndef DISPLAY_H
#define DISPLAY_H

#include <oled.h>
#include <uart.h>

// Definice adresy displeje (případně doplňte správnou hodnotu)
#define DISPLAY_ADDR 0x00

// Funkce pro inicializaci displeje
void init_display();

// Funkce pro zobrazení hodnot na displeji
void update_displa();

#endif // DISPLAY_H
