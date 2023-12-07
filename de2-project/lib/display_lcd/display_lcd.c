#include <uart.h>
#include <buttons.h>
#include <stdio.h>
#include <hd44780pcf8574.h>


#ifdef DISPLAY_ADDR
#define DISPLAY_ADDR
#endif

#define DEFAULT 0
#define SETUP_MAX_TEMP 1
#define SETUP_MIN_TEMP 2
#define SETUP_MIN_TANK_FILL 3

char string[10];

uint8_t state_lcd = DEFAULT;
uint8_t update_counter_lcd = 0;

void init_display_lcd()
{
    HD44780_PCF8574_Init(PCF8574_ADDRESS);
    HD44780_PCF8574_DisplayClear(PCF8574_ADDRESS);
    HD44780_PCF8574_DisplayOn(PCF8574_ADDRESS);

}

void set_default_ldc()
{
    state_lcd = DEFAULT;
}

void check_for_setup_lcd()
{
    if (update_counter_lcd % 2 == 0 && get_button_state(ENTER) == 0)
    {
        if (state_lcd == DEFAULT)
        {
            state_lcd = SETUP_MAX_TEMP;
        }
        else if (state_lcd == SETUP_MAX_TEMP)
        {
            state_lcd = SETUP_MIN_TEMP;
        }
        else if (state_lcd == SETUP_MIN_TEMP)
        {
            state_lcd = SETUP_MIN_TANK_FILL;
        }
        else if (state_lcd == SETUP_MIN_TANK_FILL)
        {
            state_lcd = DEFAULT;
        }
    }
}



void adjust_lcd(int16_t *value)
{
    if (get_button_state(LEFT) == 0)
    {
        (*value)--;
    }
    else if (get_button_state(RIGHT) == 0)
    {
        (*value)++;
    }
}

 void print_setup_max_temp_lcd(int16_t max_temp)
 {

//     _charMode(DOUBLESIZE);
//     oled_gotoxy(0, 0);
//     oled_puts("Max temp");
//     oled_drawLine(0, 20, 120, 20, WHITE);

//     //* display temprature
//     oled_gotoxy(6, 4);
//     itoa(max_temp, string, 10);
//     oled_puts(string);
//     oled_puts("C");

//     oled_display();
 }

 void print_setup_min_temp_lcd(uint16_t min_temp)
 {
//     oled_charMode(DOUBLESIZE);
//     oled_gotoxy(0, 0);
//     oled_puts("Min temp");
//     oled_drawLine(0, 20, 120, 20, WHITE);

//     //* display temprature
//     oled_gotoxy(6, 4);
//     itoa(min_temp, string, 10);
//     oled_puts(string);
//     oled_puts("C");

//     oled_display();
 }
 void print_setup_min_tank_fill_lcd(int16_t tank_fill)
 {
//     oled_charMode(DOUBLESIZE);
//     oled_gotoxy(0, 0);
//     oled_puts("Tank fill");
//     oled_drawLine(0, 20, 120, 20, WHITE);

//     //* display temprature
//     oled_gotoxy(6, 4);
//     itoa(tank_fill, string, 10);
//     oled_puts(string);
//     oled_puts("%");

//     oled_display();
 }

void print_default_lcd(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill)
{
    

    // oled_charMode(DOUBLESIZE);
    // oled_gotoxy(0, 0);
    // oled_puts("Smart pot");
    // oled_drawLine(0, 20, 120, 20, WHITE);

    // oled_charMode(NORMALSIZE);

    // //* display temprature
    // oled_gotoxy(0, 3);
    // oled_puts("temp. - ");

    // itoa(temp, string, 10);
    // oled_puts(string);

    // oled_puts(".");

    // itoa(temp_dec, string, 10);
    // oled_puts(string);

    // oled_puts("C");

    // //* display humidity
    // oled_gotoxy(0, 4);
    // oled_puts("hum.  - ");

    // itoa(hum, string, 10);
    // oled_puts(string);

    // oled_puts(".");

    // itoa(hum_dec, string, 10);
    // oled_puts(string);
    // oled_putc('%');

    // //* display soil humidity
    // oled_gotoxy(0, 5);
    // itoa(s_hum, string, 10);
    // oled_puts("soild - ");
    // oled_puts(string);
    // oled_putc('%');

    // //* display tank fill
    // oled_gotoxy(0, 6);
    // itoa(tank_fill, string, 10);
    // oled_puts("tank  - ");
    // oled_puts(string);

    // oled_putc('%');

    // oled_display();

    HD44780_PCF8574_PositionXY(PCF8574_ADDRESS,7,0);
    HD44780_PCF8574_DrawString(PCF8574_ADDRESS,"test");

    HD44780_PCF8574_PositionXY(PCF8574_ADDRESS,0,1);
    HD44780_PCF8574_DrawString(PCF8574_ADDRESS,"test2");

    
    
}

void update_display_lcd(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill,
                    int16_t *max_temp, int16_t *min_temp, int16_t *min_tank)
{
    switch (state_lcd)
    {
    case DEFAULT:
        print_default_lcd(temp, temp_dec, hum, hum_dec, s_hum, tank_fill);
        break;
    case SETUP_MAX_TEMP:
        adjust_lcd(max_temp);
        print_setup_max_temp_lcd(*max_temp);
        break;
    case SETUP_MIN_TEMP:
        adjust_lcd(min_temp);
        print_setup_min_temp_lcd(*min_temp);
        break;
    case SETUP_MIN_TANK_FILL:
        adjust_lcd(min_tank);
        print_setup_min_tank_fill_lcd(*min_tank);
        break;
    }

    state_lcd++;

    if (state_lcd > 100)
    {
        state_lcd = 0;
    }
}