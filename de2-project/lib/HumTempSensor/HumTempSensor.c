/***********************************************************************
 * 
 * HumTempSensor library for AVR-GCC.
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

// Adresa I2C senzoru vlhkosti a teploty
#define SENSOR_ADR 0x5C

// Adresa paměti pro údaje o vlhkosti a teplotě v senzoru
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

// Funkce pro získání celé části vzdušné vlhkosti ze senzoru
float get_air_humidity_int()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // Vrácení celé části vzdušné vlhkosti
  return (float)dht12.hum_int;
}

// Funkce pro získání desetinné části vzdušné vlhkosti ze senzoru
float get_air_humidity_dec()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // Vrácení desetinné části vzdušné vlhkosti
  return (float)dht12.hum_dec / 10.0;
}

// Funkce pro získání celé části vzdušné teploty ze senzoru
float get_air_temp_int()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // Vrácení celé části vzdušné teploty
  return (float)dht12.temp_int;
}

// Funkce pro získání desetinné části vzdušné teploty ze senzoru
float get_air_temp_dec()
{
  // Zavolání funkce pro čtení hodnot z čidla
  getDataFromSensor();
  // Vrácení desetinné části vzdušné teploty
  return (float)dht12.temp_dec;
}