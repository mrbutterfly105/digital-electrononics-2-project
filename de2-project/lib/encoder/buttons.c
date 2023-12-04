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

// //! switch zapojíš na pin2 (PD2)
// uint8_t read_switch()
// {
//     return GPIO_read(&PIND, SWITCH);
// }

// uint8_t read_clk()
// {
//     return GPIO_read(&PIND, CLK);
// }

// //!
// void update_encoder()
// {
//     uint8_t stav_clk = GPIO_read(&PIND, CLK);
//     uint8_t stav_data = GPIO_read(&PIND, DATA);
    
//     // char ch[1];
//     // itoa(stav_clk,ch,10);
//     // uart_puts(ch);

//     // itoa(stav_data,ch,10);
//     // uart_puts(ch);

//     if (stav_clk != stav_clk_pred)
//     {
//         if (GPIO_read(&PIND, DATA) != stav_clk)
//         {
//             if (pozice_encoder > 254)
//             {
//                 pozice_encoder = 0;
//             }
//             else
//             {
//                 pozice_encoder++;
//             }
//         }
//         else
//         {
//             if (pozice_encoder == 0)
//             {
//                 pozice_encoder = 255;
//             }
//             else
//             {
//                 pozice_encoder--;
//             }
//         }
//     }
//     stav_clk_pred = stav_clk;
//     stav_data_pred = stav_data;
// }