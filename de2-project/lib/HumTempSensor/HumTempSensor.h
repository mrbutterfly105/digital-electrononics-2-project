#ifndef HumTempSensor_H
#define HumTempSensor_H

#include <twi.h>

#define SENSOR_ADR 0x5C
#define SENSOR_HUM_MEM 0
#define SENSOR_TEMP_MEM 2
#define SENSOR_CHECKSUM 4

struct DHT_values_structure
{
  uint8_t hum_int;
  uint8_t hum_dec;
  uint8_t temp_int;
  uint8_t temp_dec;
  uint8_t checksum;
} dht12;



void getDataFromSensor();

/**
 * @brief  Get air humidity from the sensor.
 * @return Air humidity.
 */
float get_air_humidity_int();

float get_air_humidity_dec();

/**
 * @brief  Get air temperature from the sensor.
 * @return Air temperature.
 */

float get_air_temp_int();

float get_air_temp_dec();

#endif  