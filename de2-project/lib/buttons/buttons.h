// gpio_switch.h
/**
 * @file buttons.h
 * @defgroup Buttons <buttons.h>
 * @code #include <buttons.h> @endcode
 * @brief Button handling functions header file.
 */

#ifndef GPIO_SWITCH_H
#define GPIO_SWITCH_H

#define RIGHT PD4
#define LEFT PD3
#define ENTER PD2

#include <stdint.h>

// Deklarace funkce pro čtení stavu tlačítka
/**
 * @brief Initializes the buttons by setting the corresponding pins as input with pull-up.
 */
void init_buttons();
/**
 * @brief Gets the state of the specified button.
 * @param button The button to check (LEFT, RIGHT, or ENTER).
 * @return The state of the button (1 for pressed, 0 for not pressed).
 */
uint8_t get_button_state(uint8_t button);

#endif // GPIO_SWITCH_H
