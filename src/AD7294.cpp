#include "AD7294.h"

uint8_t AD7294::writereg(uint8_t reg, uint8_t data) //8bit
{

    Wire.beginTransmission(device_address);
    Wire.write(reg);
    Wire.write(data);
    Wire.endTransmission(true);

    return 0;
}

uint8_t AD7294::writereg(uint8_t reg, uint16_t data)  //16bit
{

    Wire.beginTransmission(device_address);
    Wire.write(reg);
    Wire.write((uint8_t)(data & 0xff00) >> 8); // msb
    Wire.write((uint8_t)(data & 0xff));        // lsb
    Wire.endTransmission(true);

    return 0;
}

uint8_t AD7294::readreg8(uint8_t reg, boolean readAgainFlag =false)
{
    uint8_t data = 0;

    Wire.beginTransmission(device_address);
    Wire.write(reg);
    Wire.endTransmission(false);

    if (readAgainFlag == false)
    {
        Wire.requestFrom(device_address, 1, true);
    }

    else
    {
        Wire.requestFrom(device_address, 1, false);
    }

    if (Wire.available() != 1)
    {
        return ERRORCODE;
    }
    data = Wire.read();

    return data;
}

uint16_t AD7294::readreg16(uint8_t reg, boolean readAgainFlag = false)
{
    uint16_t data = 0;

    Wire.beginTransmission(device_address);
    Wire.write(reg);
    Wire.endTransmission(false);

    if (readAgainFlag == false)
    {
        Wire.requestFrom(device_address, 2, true);
    }

    else
    {
        Wire.requestFrom(device_address, 2, false);
    }

    if (Wire.available() != 2)
    {
        return ERRORCODE;
    }
    data = Wire.read();

    return data;
}




 uint8_t AD7294::powerdown(uint8_t value = (POWERDOWN_ADC_REFBUFFER | POWERDOWN_DAC_REFBUFFER)){
    writereg(POWER_DOWN_REG,value);
    return 0;
 }



  uint8_t AD7294::dac_out(uint8_t channel, uint16_t data){
    writereg(channel,data);
  }



  float AD7294::temperature(uint8_t channel){
    float temp = readreg16(channel);  // out of the 16 bits D10 - D0 have the temp 

  }















uint8_t AD7294::extractMSB(uint16_t w)
{
    return (w & 0xff00) >> 8;
}

uint8_t AD7294::extractLSB(uint16_t w)
{
    return (w & 0xff);
}