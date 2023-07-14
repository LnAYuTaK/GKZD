#pragma once 
#include "IODevice.h"
#include <string>

#define ADS1115_ADDRESS1        (0x48 << 1)        /**< iic address 1 */
#define ADS1115_ADDRESS2        (0x49 << 1)        /**< iic address 2 */
#define ADS1115_ADDRESS3        (0x4A << 1)        /**< iic address 3 */
#define ADS1115_ADDRESS4        (0x4B << 1)        /**< iic address 4 */

#define ADS1115_REG_CONVERT         0x00        /**< adc result register */
#define ADS1115_REG_CONFIG          0x01        /**< chip config register */
#define ADS1115_REG_LOWRESH         0x02        /**< interrupt low threshold register */
#define ADS1115_REG_HIGHRESH        0x03        /**< interrupt high threshold register */

class ADCDevice : public IODevice
{

private:
    /* data */
public:
    enum ADDR
    {
        ADS1115_ADDR_GND = 0x00,        /**< ADDR pin connected to GND */
        ADS1115_ADDR_VCC = 0x01,        /**< ADDR pin connected to VCC */
        ADS1115_ADDR_SDA = 0x02,        /**< ADDR pin connected to SDA */
        ADS1115_ADDR_SCL = 0x03,        /**< ADDR pin connected to SCL */
    };

    enum CHANNEL
    {
        ADS1115_CHANNEL_AIN0_AIN1 = 0x00,        /**< AIN0 and AIN1 pins */
        ADS1115_CHANNEL_AIN0_AIN3 = 0x01,        /**< AIN0 and AIN3 pins */
        ADS1115_CHANNEL_AIN1_AIN3 = 0x02,        /**< AIN1 and AIN3 pins */
        ADS1115_CHANNEL_AIN2_AIN3 = 0x03,        /**< AIN2 and AIN3 pins */
        ADS1115_CHANNEL_AIN0_GND  = 0x04,        /**< AIN0 and GND pins */
        ADS1115_CHANNEL_AIN1_GND  = 0x05,        /**< AIN1 and GND pins */
        ADS1115_CHANNEL_AIN2_GND  = 0x06,        /**< AIN2 and GND pins */
        ADS1115_CHANNEL_AIN3_GND  = 0x07,        /**< AIN3 and GND pins */
    };

    enum RANGE
    {
        ADS1115_RANGE_6P144V = 0x00,        /**< 6.144V range */
        ADS1115_RANGE_4P096V = 0x01,        /**< 4.096V range */
        ADS1115_RANGE_2P048V = 0x02,        /**< 2.048V range */
        ADS1115_RANGE_1P024V = 0x03,        /**< 1.024V range */
        ADS1115_RANGE_0P512V = 0x04,        /**< 0.512V range */
        ADS1115_RANGE_0P256V = 0x05,        /**< 0.256V range */
    };

    enum RATE
    {
        ADS1115_RATE_8SPS   = 0x00,        /**< 8 sample per second */
        ADS1115_RATE_16SPS  = 0x01,        /**< 16 sample per second */
        ADS1115_RATE_32SPS  = 0x02,        /**< 32 sample per second */
        ADS1115_RATE_64SPS  = 0x03,        /**< 64 sample per second */
        ADS1115_RATE_128SPS = 0x04,        /**< 128 sample per second */
        ADS1115_RATE_250SPS = 0x05,        /**< 250 sample per second */
        ADS1115_RATE_475SPS = 0x06,        /**< 475 sample per second */
        ADS1115_RATE_860SPS = 0x07,        /**< 860 sample per second */
    };

    ADCDevice();
    ~ADCDevice()override;
    virtual void init(const char* i2cPort,
                      ADDR     adress,
                      CHANNEL  channel,
                      RANGE    range,
                      RATE     rate);

    virtual bool open() override 
    { 
     return false;
    }

    virtual void close()override;

    DriverType type() const override { 
        return this->type_; 
    }

    bool ads1115Read(uint8_t reg, int16_t *data);

    bool ads1115Write(uint8_t reg, uint16_t data);

    bool setChannel(CHANNEL channel);

    bool setRate(Rate rate);

    bool setRange(RANGE    range);

private:

    bool iicRead(uint8_t addr,uint8_t reg, uint8_t *buf, uint16_t len);

    bool iicWrite(uint8_t addr,uint8_t reg, uint8_t *buf, uint16_t len);

    uint8_t convAddr(ADDR addr);

    int fd_;
    CHANNEL  channel_;
    RANGE    range_;
    RATE     rate_;
    uint8_t addr_;
    DriverType type_;
};

