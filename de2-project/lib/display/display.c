#include <oled.h>
#include <uart.h>

#define DISPLAY_ADDR


char string[2];

void init_display(){
    oled_init(OLED_DISP_ON);
    
}

void update_displa(int16_t temp, int16_t hum, int16_t s_hum, int16_t tank_fill){
    
    oled_clrscr();

    oled_charMode(NORMALSIZE);

    oled_gotoxy(0, 2);
    
    itoa(temp, string,10);

    oled_puts(string);

    // oled_drawLine(x1, y1, x2, y2, color)
    //? oled_drawLine(0, 25, 120, 25, WHITE);
    
    // Copy buffer to display RAM
    oled_display();
}