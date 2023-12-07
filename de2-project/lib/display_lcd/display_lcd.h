#include <hd44780pcf8574.h>
#include <uart.h>
#include <buttons.h>

#define DEFAULT 0
#define SETUP_MAX_TEMP 1
#define SETUP_MIN_TEMP 2
#define SETUP_MIN_TANK_FILL 3

void init_display_lcd();
void set_default_ldc();
void check_for_setup_lcd();
void adjust_lcd(int16_t *value);

void print_setup_max_temp_lcd(int16_t max_temp);
void print_setup_min_temp_lcd(uint16_t min_temp);
void print_setup_min_tank_fill_lcd(int16_t tank_fill);

void print_default_lcd(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill);

void update_display_lcd(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill,
                        int16_t *max_temp, int16_t *min_temp, int16_t *min_tank);
