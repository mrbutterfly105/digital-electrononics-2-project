#include "rtc.h"

/**
 * @brief Converts BCD to decimal format.
 * @param val BCD value to convert.
 * @return Decimal value.
 */
uint8_t bcdToDec(uint8_t val) {
  return ( (val/16*10) + (val%16) );
}

/**
 * @brief Converts decimal to BCD format.
 * @param val Decimal value to convert.
 * @return BCD value.
 */
uint8_t decToBcd(uint8_t val) {
  return ( (val/10*16) + (val%10) );
}

/**
 * @brief Initializes RTC communication.
 */
void rtc_init() {
  
  TWBR = 72;  
  TWSR = 0x00;
}

/**
 * @brief Starts communication with the RTC.
 */
void rtc_start() {
  
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN); 
  while (!(TWCR & (1 << TWINT)));
}

/**
 * @brief Stops communication with the RTC.
 */
void rtc_stop() {
  
  TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

/**
 * @brief Writes data to the I2C.
 * @param data Data to write.
 */
void rtc_write(uint8_t data) {
  
  TWDR = data;
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));
}

/**
 * @brief Reads data from the I2C.
 * @return Read data.
 */
uint8_t rtc_read() {
  TWCR = (1 << TWINT) | (1 << TWEN);
  while (!(TWCR & (1 << TWINT)));
  return TWDR;
}

/**
 * @brief Writes seconds from RTC to the I2C.
 * @param seconds Seconds to write.
 */
void rtc_write_seconds(uint8_t seconds) { 
  rtc_start();
  rtc_write(RTC << 1);
  rtc_write(0x00); // address of seconds register
  rtc_write(decToBcd(seconds)); 
  rtc_stop();
}

/**
 * @brief Writes minutes from RTC to the I2C.
 * @param minutes Minutes to write.
 */
void rtc_write_minutes(uint8_t minutes) { 
  rtc_start();
  rtc_write(RTC << 1);
  rtc_write(0x01); // address of minutes register
  rtc_write(decToBcd(minutes)); 
  rtc_stop();
}

/**
 * @brief Writes hours from RTC to the I2C.
 * @param hours Hours to write.
 */
void rtc_write_hours(uint8_t hours) { 
  rtc_start();
  rtc_write(RTC << 1);
  rtc_write(0x02); // address of hours register
  rtc_write(decToBcd(hours)); 
  rtc_stop();
}

/**
 * @brief Reads seconds from RTC.
 * @param seconds Pointer to a variable to store the read seconds.
 */
void rtc_read_seconds(uint8_t *seconds) {
  rtc_start();
  rtc_write(RTC << 1);
  rtc_write(0x00); 
  rtc_start();
  rtc_write((RTC << 1) | 1);
  *seconds = bcdToDec(rtc_read() & 0x7F); 
  rtc_stop();
}

/**
 * @brief Reads minutes from RTC.
 * @param minutes Pointer to a variable to store the read minutes.
 */
void rtc_read_minutes(uint8_t *minutes) {
  rtc_start();
  rtc_write(RTC << 1);
  rtc_write(0x01); 
  rtc_start();
  rtc_write((RTC << 1) | 1);
  *minutes = bcdToDec(rtc_read());
  rtc_stop();
}

/**
 * @brief Reads hours from RTC.
 * @param hours Pointer to a variable to store the read hours.
 */
void rtc_read_hours(uint8_t *hours) {
  rtc_start();
  rtc_write(RTC << 1);
  rtc_write(0x02); 
  rtc_start();
  rtc_write((RTC << 1) | 1);
  *hours = bcdToDec(rtc_read() & 0x3F); 
  rtc_stop();
}
