/**
 * @file display.h
 * @brief Display functions header file.
 */

#include <oled.h>
#include <uart.h>
#include <buttons.h>

// Definition of the display address (replace with the correct value if needed)
#ifdef DISPLAY_ADDR
#define DISPLAY_ADDR 0x00
#endif

/**
 * @brief Initializes the display.
 */
void init_display();

/**
 * @brief Checks for setup mode and updates the state accordingly.
 */
void check_for_setup();

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
                    int16_t *max_temp, int16_t *min_temp, int16_t *min_tank);

/**
 * @brief Adjusts the value based on button presses.
 * @param value Pointer to the value to be adjusted.
 */
void adjust(int16_t *value);

/**
 * @brief Sets the state to DEFAULT.
 */
void set_default();

/**
 * @brief Prints the setup for maximum temperature.
 * @param max_temp Maximum temperature value to display.
 */
void print_setup_max_temp(int16_t max_temp);

/**
 * @brief Prints the setup for minimum temperature.
 * @param min_temp Minimum temperature value to display.
 */
void print_setup_min_temp(uint16_t min_temp);

/**
 * @brief Prints the setup for minimum tank fill.
 * @param tank_fill Tank fill value to display.
 */
void print_setup_min_tank_fill(int16_t tank_fill);

/**
 * @brief Prints the default display.
 * @param temp Temperature value to display.
 * @param temp_dec Temperature decimal value to display.
 * @param hum Humidity value to display.
 * @param hum_dec Humidity decimal value to display.
 * @param s_hum Soil humidity value to display.
 * @param tank_fill Tank fill value to display.
 */
void print_default(int16_t temp, int16_t temp_dec, int16_t hum, int16_t hum_dec, int16_t s_hum, int16_t tank_fill);
