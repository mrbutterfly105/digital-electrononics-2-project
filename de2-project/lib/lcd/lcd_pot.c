#include <avr/io.h>
#include <util/delay.h>
#include <twi.h>  // Vložení vlastní knihovny pro I2C komunikaci

// Funkce pro I2C inicializaci

display_values(){
    oled_init(OLED_DISP_ON);
    oled_clrscr();

    oled_charMode(DOUBLESIZE);
    oled_puts("OLED disp.");

    oled_charMode(NORMALSIZE);

    // oled_gotoxy(x, y)
    oled_gotoxy(0, 2);
    oled_puts("128x64, SHH1106");

    // oled_drawLine(x1, y1, x2, y2, color)
    oled_drawLine(0, 25, 120, 25, WHITE);

    oled_gotoxy(0, 4);
    oled_puts("AVR course, Brno");

    // Copy buffer to display RAM
    oled_display();
}