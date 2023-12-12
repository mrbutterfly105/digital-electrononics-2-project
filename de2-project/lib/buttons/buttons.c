/**
 * @file buttons.c
 * @brief Button handling functions implementation file.
 */
#include <gpio.h>
#include <uart.h>

#define RIGHT PD4
#define LEFT PD2
#define ENTER PD3

/**
 * @brief Initializes the buttons by setting the corresponding pins as input with pull-up.
 */
void init_buttons()
{
    GPIO_mode_input_pullup(&DDRD, ENTER);
    GPIO_mode_input_pullup(&DDRD, LEFT);
    GPIO_mode_input_pullup(&DDRD, RIGHT);

}

// LEFT, RIGHT, ENTER
/**
 * @brief Gets the state of the specified button.
 * @param button The button to check (LEFT, RIGHT, or ENTER).
 * @return The state of the button (1 for pressed, 0 for not pressed).
 */
uint8_t get_button_state(uint8_t button){
    return GPIO_read(&PIND, button);
}
