

#include <gpio.h>
#define SENZOR_PIN PC1 // A1
#define LAMP PB2       // D3

char time_string[9];
char senzor[10];

void light_init()
{
    GPIO_mode_input(&DDRC, SENZOR_PIN);
    GPIO_mode_output(&DDRB, LAMP);
}
uint16_t get_ambient_light_state()
{
    return GPIO_read(&PINC, SENZOR_PIN);
}

void set_rtc(int16_t hours, int16_t minutes, int16_t seconds)
{
    rtc_write_seconds(seconds);
    rtc_write_minutes(minutes);
    rtc_write_hours(hours);
}
void update_light(hours, minutes, seconds)
{
    if ((hours >= 18 && hours <= 23) || (hours >= 0 && hours < 7) || get_ambient_light_state() == 0)
    {
        GPIO_write_high(&PORTB, LAMP); // Zapnutí lampy
    }
    else
    {
        // uart_puts("LED nesvítí\n");
        GPIO_write_low(&PORTB, LAMP); // Vypnutí lampy
    }
}
