#ifndef AD7294_H
#define AD7294_H
#include <Arduino.h>
#include <Wire.h>
#include "misc.h"

///////////////////////
#define ERRORCODE8 0xFF
#define ERRORCODE 0xFFFF

#define CMD_REG 0x00 // W

#define ADC_RESULT_REG 0x01 // R
#define DACA 0x01     // W

#define TSENSE1_RESULT 0x02 // R
#define DACB 0x02     // W

#define TSENSE2_RESULT 0x03 // R
#define DACC 0x03     // W

#define TSENSEINT_RESULT 0x04 // R
#define DACD 0x04       // W

#define ALERT_STATUS_REG_A 0x05 // R/W
#define ALERT_STATUS_REG_B 0x06 // R/W
#define ALERT_STATUS_REG_C 0x07 // R/W

#define CHANNEL_SEQ_REG 0x08 // R/W

#define CONFIG_REG 0x09 // R/W

#define POWER_DOWN_REG 0x0A // R/W

#define DATALOW_VIN0_REG 0x0B    // R/W
#define DATAHIGH_VIN0_REG 0x0C   // R/W
#define HYSTERESIS_VIN0_REG 0x0D // R/W

#define DATALOW_VIN1_REG 0x0E    // R/W
#define DATAHIGH_VIN1_REG 0x0F   // R/W
#define HYSTERESIS_VIN1_REG 0x10 // R/W

#define DATALOW_VIN2_REG 0x11    // R/W
#define DATAHIGH_VIN2_REG 0x12   // R/W
#define HYSTERESIS_VIN2_REG 0x13 // R/W

#define DATALOW_VIN3_REG 0x14    // R/W
#define DATAHIGH_VIN3_REG 0x15   // R/W
#define HYSTERESIS_VIN3_REG 0x16 // R/W

#define DATALOW_ISENSE1_REG 0x17    // R/W
#define DATAHIGH_ISENSE1_REG 0x18   // R/W
#define HYSTERESIS_ISENSE1_REG 0x19 // R/W

#define DATALOW_ISENSE2_REG 0x1A    // R/W
#define DATAHIGH_ISENSE2_REG 0x1B   // R/W
#define HYSTERESIS_ISENSE2_REG 0x1C // R/W

#define DATALOW_TSENSE1_REG 0x1D    // R/W
#define DATAHIGH_TSENSE1_REG 0x1E   // R/W
#define HYSTERESIS_TSENSE1_REG 0x1F // R/W

#define DATALOW_TSENSE2_REG 0x20    // R/W
#define DATAHIGH_TSENSE2_REG 0x21   // R/W
#define HYSTERESIS_TSENSE2_REG 0x22 // R/W

#define DATALOW_TSENSEINT_REG 0x23    // R/W
#define DATAHIGH_TSENSEINT_REG 0x24   // R/W
#define HYSTERESIS_TSENSEINT_REG 0x25 // R/W

#define TSENSE1_OFFSET_REG 0x26 // R/W
#define TSENSE2_OFFSET_REG 0x27 // R/W

#define FACTORY_TEST_MODE1_REG 0x40 // N/A
#define FACTORY_TEST_MODE2_REG 0x41 // N/A

#define AD7294_ADC_CH_VIN_1 1
#define AD7294_ADC_CH_VIN_2 2
#define AD7294_ADC_CH_VIN_3 3
#define AD7294_ADC_CH_VIN_0 0
#define AD7294_ADC_CH_ISENSE_1 4
#define AD7294_ADC_CH_ISENSE_2 5
#define AD7294_ADC_CH_TSENSE_1 6
#define AD7294_ADC_CH_TSENSE_2 7

#define AD7294_LIMIT_VIN_1 1
#define AD7294_LIMIT_VIN_2 2
#define AD7294_LIMIT_VIN_3 3
#define AD7294_LIMIT_VIN_0 0
#define AD7294_LIMIT_ISENSE_1 4
#define AD7294_LIMIT_ISENSE_2 5
#define AD7294_LIMIT_TSENSE_1 6
#define AD7294_LIMIT_TSENSE_2 7
#define AD7294_LIMIT_TSENSE_INT 8

// Alert Reg A
#define ADV7294_ALERT_VIN_3_HIGH 0x800000
#define ADV7294_ALERT_VIN_3_LOW 0x400000
#define ADV7294_ALERT_VIN_2_HIGH 0x200000
#define ADV7294_ALERT_VIN_2_LOW 0x100000
#define ADV7294_ALERT_VIN_1_HIGH 0x080000
#define ADV7294_ALERT_VIN_1_LOW 0x040000
#define ADV7294_ALERT_VIN_0_HIGH 0x020000
#define ADV7294_ALERT_VIN_0_LOW 0x010000
// Alert Reg B
#define ADV7294_ALERT_ISENSE_2_OVERRANGE 0x002000
#define ADV7294_ALERT_ISENSE_1_OVERRANGE 0x001000
#define ADV7294_ALERT_ISENSE_2_HIGH 0x000800
#define ADV7294_ALERT_ISENSE_2_LOW 0x000400
#define ADV7294_ALERT_ISENSE_1_HIGH 0x000200
#define ADV7294_ALERT_ISENSE_1_LOW 0x000100
// Alert Reg C
#define ADV7294_ALERT_OPENDIODE 0x000080
#define ADV7294_ALERT_OVERTEMP 0x000040
#define ADV7294_ALERT_TSENSE_INT_HIGH 0x000020
#define ADV7294_ALERT_TSENSE_INT_LOW 0x000010
#define ADV7294_ALERT_TSENSE_2_HIGH 0x000008
#define ADV7294_ALERT_TSENSE_2_LOW 0x000004
#define ADV7294_ALERT_TSENSE_1_HIGH 0x000002
#define ADV7294_ALERT_TSENSE_1_LOW 0x000001


//POWERDOWN
#define POWERDOWN_ADC_DAC_REF_BUF_AND_DAC_ISENSE1_ISENSE2_ALERTS 0x80
#define POWERDOWN_ADC_REFBUFFER 0x20
#define POWERDOWN_DAC_REFBUFFER 0x10
#define POWERDOWN_TEMP_SENSOR 0x08
#define POWERDOWN_ISENSE1_ALERTS 0x04
#define POWERDOWN_ISENSE2_ALERTS 0x02
#define POWERDOWN_DAC_HIGH_IMP 0x01

#define DEFAULT_POWER_DOWN_VALUE 0x70


class AD7294
{
public:
  //   ADC_RESULTS adc_results[8];

  void init(uint8_t device_address);
  uint8_t writereg(uint8_t reg, uint16_t data);
  uint8_t writereg(uint8_t reg, uint8_t data);

  uint8_t readreg8(uint8_t reg, boolean readAgainFlag);
  uint16_t readreg16(uint8_t reg, boolean readAgainFlag);







  uint8_t dac_out(uint8_t channel, uint16_t data);
  uint8_t powerdown(uint8_t value);
  uint8_t read_temperature(int channel, float *temp);
  uint8_t readadcs_autocycling();
  uint8_t readadcs_autocycling(uint8_t mask);
  uint8_t set_limit(uint8_t limit, uint16_t min_value, uint16_t max_value, uint16_t hyst);

  uint32_t get_alerts();
  void clear_alerts();
  uint16_t temp_float_to_limitreg(float temp);

private:
  uint8_t device_address;

  uint8_t extractLSB(uint16_t w);
  uint8_t extractMSB(uint16_t w);
};

#endif
