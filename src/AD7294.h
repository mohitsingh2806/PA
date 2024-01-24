#ifndef AD7294_H
#define AD7294_H
#include <Arduino.h>
#include <Wire.h>
#include "misc.h"

///////////////////////

#define CMD_REG                     0x00 // W

#define ADC_RESULT_REG              0x01 // R
#define DACA_VALUE                  0x01 // W

#define TSENSE1_RESULT              0x02 // R
#define DACB_VALUE                  0x02 // W

#define TSENSE2_RESULT              0x03 // R
#define DACC_VALUE                  0x03 // W

#define TSENSEINT_RESULT            0x04 // R
#define DACD_VALUE                  0x04 // W

#define ALERT_STATUS_REG_A          0x05 // R/W
#define ALERT_STATUS_REG_B          0x06 // R/W
#define ALERT_STATUS_REG_C          0x07 // R/W

#define CHANNEL_SEQ_REG             0x08 // R/W

#define CONFIG_REG                  0x09 // R/W

#define POWER_DOWN_REG              0x0A // R/W

#define DATALOW_VIN0_REG            0x0B // R/W
#define DATAHIGH_VIN0_REG           0x0C // R/W
#define HYSTERESIS_VIN0_REG         0x0D // R/W

#define DATALOW_VIN1_REG            0x0E // R/W
#define DATAHIGH_VIN1_REG           0x0F // R/W
#define HYSTERESIS_VIN1_REG         0x10 // R/W

#define DATALOW_VIN2_REG            0x11 // R/W
#define DATAHIGH_VIN2_REG           0x12 // R/W
#define HYSTERESIS_VIN2_REG         0x13 // R/W

#define DATALOW_VIN3_REG            0x14 // R/W
#define DATAHIGH_VIN3_REG           0x15 // R/W
#define HYSTERESIS_VIN3_REG         0x16 // R/W

#define DATALOW_ISENSE1_REG         0x17 // R/W
#define DATAHIGH_ISENSE1_REG        0x18 // R/W
#define HYSTERESIS_ISENSE1_REG      0x19 // R/W

#define DATALOW_ISENSE2_REG         0x1A // R/W
#define DATAHIGH_ISENSE2_REG        0x1B // R/W
#define HYSTERESIS_ISENSE2_REG      0x1C // R/W

#define DATALOW_TSENSE1_REG         0x1D // R/W
#define DATAHIGH_TSENSE1_REG        0x1E // R/W
#define HYSTERESIS_TSENSE1_REG      0x1F // R/W

#define DATALOW_TSENSE2_REG         0x20 // R/W
#define DATAHIGH_TSENSE2_REG        0x21 // R/W
#define HYSTERESIS_TSENSE2_REG      0x22 // R/W

#define DATALOW_TSENSEINT_REG       0x23 // R/W
#define DATAHIGH_TSENSEINT_REG      0x24 // R/W
#define HYSTERESIS_TSENSEINT_REG    0x25 // R/W

#define TSENSE1_OFFSET_REG          0x26 // R/W
#define TSENSE2_OFFSET_REG          0x27 // R/W

#define FACTORY_TEST_MODE1_REG      0x40 // N/A
#define FACTORY_TEST_MODE2_REG      0x41 // N/A





class AD7294
{
public:
//   ADC_RESULTS adc_results[8];

  void init (uint8_t i2c_addr);
  boolean writereg_u16 (uint8_t reg, uint16_t data);
  boolean readreg_u16 (uint8_t reg, uint16_t *data);
  boolean writereg_u8 (uint8_t reg, uint8_t data);
  boolean readreg_u8 (uint8_t reg, uint8_t *data);
  boolean readagain_u16 (uint16_t *data);
  boolean readagain_u8 (uint8_t *data);

  boolean set_dac(int channel, uint16_t value);
  boolean read_temperature(int channel, float *temp);



  boolean set_limit( uint8_t limit, uint16_t min_value, uint16_t max_value, uint16_t hyst);
  
  uint32_t get_alerts();
  void clear_alerts();
  uint16_t temp_float_to_limitreg(float temp);
  
private:
  int ad7294_i2c_addr = 0x61;
  
  uint8_t lsb (uint16_t w);
  uint8_t msb (uint16_t w);


};

class AD7294{
uint8_t device_address;
public:
void init (uint8_t device_address);
void
private:



};
















#endif
