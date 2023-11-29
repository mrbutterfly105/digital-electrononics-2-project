#include <oled.h>
#include <uart.h>

#define DISPLAY_ADDR

char string[10];

void init_display()
{
    oled_init(OLED_DISP_ON);
}

void update_display(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill)
{

    //oled_clrscr();

    oled_charMode(DOUBLESIZE);
    oled_gotoxy(0, 0);
    oled_puts("Smart pot");
    oled_drawLine(0, 20, 120, 20, WHITE);


    oled_charMode(NORMALSIZE);

    //* display temprature
    oled_gotoxy(0, 3);
    oled_puts("temp. - ");
    
    itoa(temp, string, 10);
    oled_puts(string);
    
    oled_puts(".");

    itoa(temp_dec, string, 10);
    oled_puts(string);
    
    oled_puts("C");

    //* display humidity
    oled_gotoxy(0, 4);
    oled_puts("hum.  - ");
    
    itoa(hum, string, 10);
    oled_puts(string);

    oled_puts(".");

    itoa(hum_dec,string,10);
    oled_puts(string);
    oled_putc('%');

    //* display soil humidity
    oled_gotoxy(0, 5);
    itoa(s_hum, string, 10);
    oled_puts("soild - ");
    oled_puts(string);
    oled_putc('%');

    //* display tank fill
    oled_gotoxy(0, 6);
    itoa(tank_fill, string, 10);
    oled_puts("tank  - ");
    oled_puts(string);
    oled_putc('%');

    // oled_drawLine(x1, y1, x2, y2, color)
    //? oled_drawLine(0, 25, 120, 25, WHITE);

    // Copy buffer to display RAM
    oled_display();
}