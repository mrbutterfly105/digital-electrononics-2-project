/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * 
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2023 Jakub Pachel
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/


/* Includes ----------------------------------------------------------*/
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




void getDataFromSensor()
{
  twi_init();
  // Čtení hodnot z čidla DHT12
  twi_start();
  if (twi_write((SENSOR_ADR << 1) | TWI_WRITE) == 0)
  {
    twi_write(SENSOR_HUM_MEM);
    twi_stop();
    twi_start();
    twi_write((SENSOR_ADR << 1) | TWI_READ);
    dht12.hum_int = twi_read(TWI_ACK);
    dht12.hum_dec = twi_read(TWI_NACK);
    // dht12.hum_int = 42;
    //dht12.hum_dec = 0;
  }
  

  

  twi_start();
  if (twi_write((SENSOR_ADR << 1) | TWI_WRITE) == 0)
  {
    twi_write(SENSOR_TEMP_MEM);
    twi_stop();
    twi_start();
    twi_write((SENSOR_ADR << 1) | TWI_READ);
    dht12.temp_int = twi_read(TWI_ACK);
    dht12.temp_dec = twi_read(TWI_NACK);
    
  }
  

  twi_start();
  if (twi_write((SENSOR_ADR << 1) | TWI_WRITE) == 0)
  {
    twi_write(SENSOR_CHECKSUM);
    twi_stop();
    twi_start();
    twi_write((SENSOR_ADR << 1) | TWI_READ);
    dht12.checksum = twi_read(TWI_NACK);
  }
  twi_stop();
}

float get_air_humidity_int()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // vypsání celé hodnoty procent vlhkosti vzduchu
  return (float)dht12.hum_int ;
}
float get_air_humidity_dec()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // vypsání desetiné hodnoty procent vlhkosti vzduchu
  return  (float)dht12.hum_dec / 10.0;
}

float get_air_temp_int()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // vypsání celé hodnoty teploty
 return (float)dht12.temp_int;

}
float get_air_temp_dec()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // vypsání desetinné hodnoty teploty
 return (float)dht12.temp_dec;

}