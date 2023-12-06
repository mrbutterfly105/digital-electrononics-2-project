#include <gpio.h>
#include <uart.h>

#define RIGHT PD4
#define LEFT PD2
#define ENTER PD3



void init_buttons()
{
    GPIO_mode_input_pullup(&DDRD, ENTER);
    GPIO_mode_input_pullup(&DDRD, LEFT);
    GPIO_mode_input_pullup(&DDRD, RIGHT);

}

// LEFT, RIGHT, ENTER
uint8_t get_button_state(uint8_t button){
    return GPIO_read(&PIND, button);
}
