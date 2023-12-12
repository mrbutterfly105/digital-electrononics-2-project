#include <gpio.h>

#define SENZOR_PIN PC2 // A1
#define LAMP PB2       // D10

char time_string[9];
char senzor[10];

/**
 * @brief Initialize the light system
 */
void light_init()
{
    GPIO_mode_input(&DDRC, SENZOR_PIN);
    GPIO_mode_output(&DDRB, LAMP);      
}

/**
 * @brief Get the light state from the sensor
 * @return The light state
 */
uint16_t get_ambient_light_state()
{
    return GPIO_read(&PINC, SENZOR_PIN); 
}

/**
 * @brief Set the real-time clock (RTC) time
 * @param hours The hours value
 * @param minutes The minutes value
 * @param seconds The seconds value
 */
void set_rtc(int16_t hours, int16_t minutes, int16_t seconds)
{
    rtc_write_seconds(seconds); 
    rtc_write_minutes(minutes);
    rtc_write_hours(hours);
}

void update_light()
{   
    if ( get_ambient_light_state() == 0)
    {
        GPIO_write_high(&PORTB, LAMP);
    }
    else
    {
        GPIO_write_low(&PORTB, LAMP);
    }
}
