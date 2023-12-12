/**
 * @file display.c
 * @brief Display functions implementation file.
 */

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

/**
 * @brief Initializes the display.
 */
void init_display()
{
    oled_init(OLED_DISP_ON);
}

/**
 * @brief Sets the state to DEFAULT.
 */
void set_default()
{
    state = DEFAULT;
}

/**
 * @brief Checks for setup mode and updates the state accordingly.
 */
void check_for_setup()
{
    if (update_counter % 1 == 0 && get_button_state(ENTER) == 0)
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

/**
 * @brief Adjusts the value based on button presses.
 * @param value Pointer to the value to be adjusted.
 */
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

/**
 * @brief Prints the setup for maximum temperature.
 * @param max_temp Maximum temperature value to display.
 */
void print_setup_max_temp(int16_t max_temp)
{
    // Function implementation...
}

/**
 * @brief Prints the setup for minimum temperature.
 * @param min_temp Minimum temperature value to display.
 */
void print_setup_min_temp(uint16_t min_temp)
{
    // Function implementation...
}

/**
 * @brief Prints the setup for minimum tank fill.
 * @param tank_fill Tank fill value to display.
 */
void print_setup_min_tank_fill(int16_t tank_fill)
{
    // Function implementation...
}

/**
 * @brief Prints the default display.
 * @param temp Temperature value to display.
 * @param temp_dec Temperature decimal value to display.
 * @param hum Humidity value to display.
 * @param hum_dec Humidity decimal value to display.
 * @param s_hum Soil humidity value to display.
 * @param tank_fill Tank fill value to display.
 */
void print_default(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill)
{
<<<<<<< Updated upstream
    // Function implementation...
=======
    // oled_clrscr();

    oled_charMode(DOUBLESIZE);
    oled_gotoxy(0, 0);
    oled_puts("Smart pot");
    oled_drawLine(0, 20, 120, 20, WHITE);

    oled_charMode(NORMALSIZE);

    //* display temprature
    oled_gotoxy(0, 3);
    oled_puts("  temp. - ");

    itoa(temp, string, 10);
    oled_puts(string);

    oled_puts(".");

    itoa(temp_dec, string, 10);
    oled_puts(string);

    oled_puts("C");

    //* display humidity
    oled_gotoxy(0, 4);
    oled_puts("  hum.  - ");

    itoa(hum, string, 10);
    oled_puts(string);

    oled_puts(".");

    itoa(hum_dec, string, 10);
    oled_puts(string);
    oled_putc('%');

    //* display soil humidity
    oled_gotoxy(0, 5);
    itoa(s_hum, string, 10);
    oled_puts("  soilh - ");
    oled_puts(string);
    oled_putc('%');

    //* display tank fill
    oled_gotoxy(0, 6);
    itoa(tank_fill, string, 10);
    oled_puts("  tank  - ");
    oled_puts(string);

    oled_putc('%');

    // oled_drawLine(x1, y1, x2, y2, color)
    //? oled_drawLine(0, 25, 120, 25, WHITE);

    // Copy buffer to display RAM
    oled_display();
>>>>>>> Stashed changes
}

/**
 * @brief Updates the display based on the current state.
 * @param temp Temperature value to display.
 * @param temp_dec Temperature decimal value to display.
 * @param hum Humidity value to display.
 * @param hum_dec Humidity decimal value to display.
 * @param s_hum Soil humidity value to display.
 * @param tank_fill Tank fill value to display.
 * @param max_temp Pointer to the maximum temperature value.
 * @param min_temp Pointer to the minimum temperature value.
 * @param min_tank Pointer to the minimum tank fill value.
 */
void update_display(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill,
                    int16_t *max_temp, int16_t *min_temp, int16_t *min_tank)
{
    // Function implementation...
}
