/***********************************************************************
 *
 * Soil library for capacitive soil moisture sensor (v1.2) + pump control functions.
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h> // AVR device-specific IO definitions, data type declarations
#include <soil.h>   // Include header file
#include <gpio.h>   // Include GPIO library

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: getSoilHumidityPercentage()
 * Purpose:  Measure soil humidity using the capacitive sensor. Reads the value from capacitive sensor connected to pin ADC0 and return it as percentage of maximum value
 * Input(s): None, the boundaries for percentage calculation are hardcoded for the sensor
 * Returns:  Percentage value in the form of integer
 **********************************************************************/
uint8_t getSoilHumidityPercentage()
{
    volatile uint16_t ADCvalue; // value returned by ADC
    float percent;              // percentage calculation handling
    uint8_t pct;                // return value
    uint16_t max = 970;         // 0-1024 ... 0-5V, set maximum level of ADC, which will equal to 100 %, derived experimentally
    uint16_t min = 700;         // 0-1024, set minimum voltage corresponding to 0 %, derived experimentally
    ADMUX &= ~(1 << REFS0);
    ADMUX |= (1 << REFS0);                                             // Set reference Vref to AVCC, REFS1 = 0, REFS0 = 1
    ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0)); // Set ADC input source to ADC0, MUX3:0 = 0000
    ADMUX &= ~(1 << ADLAR);                                            // Set result register to be right adjusted, ADLAR = 0
    ADCSRA |= (1 << ADEN);                                             // Enable ADC conversion, ADEN = 1
    // ADCSRA |= (1<<ADIE);                                     // Enable ADC interrupt, ADIE = 1
    ADCSRA |= ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)); // Set frequency division factor to 128, Arduino Uno clock = 16 MHz, ADC clock has to be between 50 and 200 kHz
    ADCSRA |= (1 << ADSC);                                  // Start ADC conversion
    while ((ADCSRA & (1 << ADIF)) == 0)
    {
        ;
    };                      // wait for conversion to finish (polling method)
    ADCvalue = ADC;         // ADC finished, put result variable into ADCvalue
    ADCSRA &= ~(1 << ADIF); // clear ADIF after conversion (ADIF is not cleared automatically unless we are using interrupt method)
    percent = (float)(ADCvalue - min) / (max - min) * 100; // calculate percentage, normalized to the interval defined by max and min variables
    pct = (int)percent;                                    // convert float back to int (with a small flooring error)
    pct = 100 - pct;                                       // invert percentage value, higher moisture (moist soil) -> lower voltage
    if (pct > 100)
    {
        pct = 100;
    }
    if (pct < 1)
    {
        pct = 0;
    }

    return pct;
}

/**********************************************************************
 * Function: getTankLevelPercentage()
 * Purpose:  Measure tank level using the capacitive sensor. Reads the value from capacitive sensor connected to pin ADC1 and return it as percentage of maximum value.
 * Input(s): None, the boundaries for percentage calculation are hardcoded for the sensor
 * Returns:  Percentage value in the form of integer
 **********************************************************************/
uint8_t getTankLevelPercentage()
{
    uint16_t ADCvalue;  // value returned by ADC
    float percent;      // percentage calculation handling
    uint8_t pct;        // return value
    uint16_t max = 970; // 0-1024 ... 0-5V, set maximum level of ADC, which will equal to 100 %, derived experimentally
    uint16_t min = 700; // 0-1024, set minimum voltage corresponding to 0 %, derived experimentally
    ADMUX &= ~(1 << REFS0);
    ADMUX |= (1 << REFS0); // Set reference Vref to AVCC, REFS1 = 0, REFS0 = 1
    ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1));
    ADMUX |= (1 << MUX0);   // Set ADC input source to ADC1, MUX3:0 = 0001
    ADMUX &= ~(1 << ADLAR); // Set result register to be right adjusted, ADLAR = 0
    ADCSRA |= (1 << ADEN);  // Enable ADC conversion, ADEN = 1
    // ADCSRA |= (1<<ADIE);                                             // Enable ADC interrupt, ADIE = 1
    ADCSRA |= ((1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)); // Set frequency division factor to 128, Arduino Uno clock = 16 MHz, ADC clock has to be between 50 and 200 kHz
    ADCSRA |= (1 << ADSC);                                  // Start ADC conversion
    while ((ADCSRA & (1 << ADIF)) == 0)
    {
        ;
    };                                                     // wait for conversion to finish (polling method)
    ADCvalue = ADC;                                        // ADC finished, put result variable into ADCvalue
    ADCSRA &= ~(1 << ADIF);                                // clear ADIF after conversion (ADIF is not cleared automatically unless we are using interrupt method)
    percent = (float)(ADCvalue - min) / (max - min) * 100; // calculate percentage, normalized to the interval defined by max and min variables
    pct = (int)percent;                                    // convert float back to int (with a small flooring error)
    pct = 100 - pct;                                       // invert percentage value, higher moisture (full tank) -> lower voltage
   if (pct > 100)
    {
        pct = 100;
    }
    if (pct < 1)
    {
        pct = 0;
    }

    return pct;
}
/**********************************************************************
 * Function: pumpTurnOff()
 * Purpose:  Turn off pump connected to pin PB0. Changes mode of pin PB0 to output and sets its value to digital 1.
 * Input(s): None
 * Returns:  None
 **********************************************************************/
void pumpTurnOff()
{
    GPIO_mode_output(&DDRB, PB0); // Change mode of pin PB0 to output
    GPIO_write_high(&PORTB, PB0); // Write logical 1 to the pin
}
/**********************************************************************
 * Function: pumpTurnOn()
 * Purpose:  Turn on pump connected to pin PB0. Changes mode of pin PB0 to output and sets its value to digital 0.
 * Input(s): None
 * Returns:  None
 **********************************************************************/
void pumpTurnOn()
{
    GPIO_mode_output(&DDRB, PB0); // Change mode of pin PB0 to output
    GPIO_write_low(&PORTB, PB0);  // Write logical 0 to the pin
}
