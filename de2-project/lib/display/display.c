#include <oled.h>
#include <uart.h>
#include <buttons.h>
#include <stdio.h>

#ifdef DISPLAY_ADDR
#define DISPLAY_ADDR
#endif

#define DEFAULT 0
#define SETUP_MAX_TEMP 1
#define SETUP_MIN_TEMP 2
#define SETUP_MIN_TANK_FILL 3

char string[10];

uint8_t state = DEFAULT;
uint8_t update_counter = 0;

void init_display()
{
    oled_init(OLED_DISP_ON);
}

void set_default()
{
    state = DEFAULT;
}

void check_for_setup()
{
    if (update_counter % 2 == 0 && get_button_state(ENTER) == 0)
    {
        if (state == DEFAULT)
        {
            state = SETUP_MAX_TEMP;
        }
        else if (state == SETUP_MAX_TEMP)
        {
            state = SETUP_MIN_TEMP;
        }
        else if (state == SETUP_MIN_TEMP)
        {
            state = SETUP_MIN_TANK_FILL;
        }
        else if (state == SETUP_MIN_TANK_FILL)
        {
            state = DEFAULT;
        }
        oled_clrscr();
    }
}

void adjust(int16_t *value)
{
    if (get_button_state(LEFT) == 0)
    {
        (*value)--;
        oled_clrscr();
    }
    else if (get_button_state(RIGHT) == 0)
    {
        (*value)++;
        oled_clrscr();
    }
}

void print_setup_max_temp(int16_t max_temp)
{

    oled_charMode(DOUBLESIZE);
    oled_gotoxy(0, 0);
    oled_puts("Max temp");
    oled_drawLine(0, 20, 120, 20, WHITE);

    //* display temprature
    oled_gotoxy(6, 4);
    itoa(max_temp, string, 10);
    oled_puts(string);
    oled_puts("C");

    oled_display();
}

void print_setup_min_temp(uint16_t min_temp)
{
    oled_charMode(DOUBLESIZE);
    oled_gotoxy(0, 0);
    oled_puts("Min temp");
    oled_drawLine(0, 20, 120, 20, WHITE);

    //* display temprature
    oled_gotoxy(6, 4);
    itoa(min_temp, string, 10);
    oled_puts(string);
    oled_puts("C");

    oled_display();
}
void print_setup_min_tank_fill(int16_t tank_fill)
{
    oled_charMode(DOUBLESIZE);
    oled_gotoxy(0, 0);
    oled_puts("Tank fill");
    oled_drawLine(0, 20, 120, 20, WHITE);

    //* display temprature
    oled_gotoxy(6, 4);
    itoa(tank_fill, string, 10);
    oled_puts(string);
    oled_puts("%");

    oled_display();
}

void print_default(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill)
{
    // oled_clrscr();

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

    itoa(hum_dec, string, 10);
    oled_puts(string);
    oled_putc('%');

    //* display soil humidity
    oled_gotoxy(0, 5);
    itoa(s_hum, string, 10);
    oled_puts("soilh - ");
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
void update_display(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill,
                    int16_t *max_temp, int16_t *min_temp, int16_t *min_tank)
{
    switch (state)
    {
    case DEFAULT:
        print_default(temp, temp_dec, hum, hum_dec, s_hum, tank_fill);
        break;
    case SETUP_MAX_TEMP:
        adjust(max_temp);
        print_setup_max_temp(*max_temp);
        break;
    case SETUP_MIN_TEMP:
        adjust(min_temp);
        print_setup_min_temp(*min_temp);
        break;
    case SETUP_MIN_TANK_FILL:
        adjust(min_tank);
        print_setup_min_tank_fill(*min_tank);
        break;
    }

    update_counter++;

    if (update_counter > 100)
    {
        update_counter = 0;
    }
}