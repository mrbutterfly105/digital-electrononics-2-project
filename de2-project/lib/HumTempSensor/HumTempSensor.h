#ifndef HumTempSensor_H
#define HumTempSensor_H

#include <twi.h>

// I2C adresa senzoru vlhkosti a teploty
#define SENSOR_ADR 0x5C

// Adresy paměti pro údaje o vlhkosti a teplotě v senzoru
#define SENSOR_HUM_MEM 0
#define SENSOR_TEMP_MEM 2

// Adresa paměti pro kontrolní součet v datech ze senzoru
#define SENSOR_CHECKSUM 4

// Struktura pro ukládání hodnot vlhkosti a teploty získaných ze senzoru
struct DHT_values_structure
{
  uint8_t hum_int;  // Celá část vlhkosti
  uint8_t hum_dec;  // Desetinná část vlhkosti
  uint8_t temp_int; // Celá část teploty
  uint8_t temp_dec; // Desetinná část teploty
  uint8_t checksum; // Kontrolní součet pro zajištění integrity dat
} dht12;

// Funkce pro získání dat ze senzoru vlhkosti a teploty
void getDataFromSensor();

/**
 * @brief  Get the integer part of air humidity from the sensor.
 * @return Integer part of air humidity.
 */
float get_air_humidity_int();

/**
 * @brief  Get the decimal part of air humidity from the sensor.
 * @return Decimal part of air humidity.
 */
float get_air_humidity_dec();

/**
 * @brief  Get the integer part of air temperature from the sensor.
 * @return Integer part of air temperature.
 */
float get_air_temp_int();

/**
 * @brief  Get the decimal part of air temperature from the sensor.
 * @return Decimal part of air temperature.
 */
float get_air_temp_dec();

#endif  