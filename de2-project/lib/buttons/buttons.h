// gpio_switch.h

#ifndef GPIO_SWITCH_H
#define GPIO_SWITCH_H

#define RIGHT PD4
#define LEFT PD3
#define ENTER PD2

#include <stdint.h>

// Deklarace funkce pro čtení stavu tlačítka
void init_buttons();
uint8_t get_button_state(uint8_t button);

#endif // GPIO_SWITCH_H
