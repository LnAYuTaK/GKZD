#include "ADCDevice.h"
#include "CLog.h"
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdarg.h>
#include <unistd.h>

ADCDevice::ADCDevice()
    :type_(IODevice::ADCDeviceType)
    ,addr_(0)
{
    
}

void ADCDevice::init(const char* i2cPort,
                      ADDR     adress,
                      CHANNEL  channel,
                      RANGE    range,
                      RATE     rate)
{
   addr_ = convAddr(adress);
   channel_  = channel;
   range_ = range;
   rate_  = rate;
}

void ADCDevice::close()
{
    int fd = fd_;
    ::close(fd);
}

uint8_t ADCDevice::convAddr(ADDR adress)
{
    switch (adress)
    {
        case ADS1115_ADDR_GND:
            return ADS1115_ADDRESS1;
        case ADS1115_ADDR_VCC:
            return ADS1115_ADDRESS2;
        case ADS1115_ADDR_SDA:
            return ADS1115_ADDRESS3;
        case  ADS1115_ADDR_SCL:
            return ADS1115_ADDRESS4;
        default:
            break;
    }
 return ADS1115_ADDRESS1;
}

bool ADCDevice::ads1115Read(uint8_t reg, int16_t *data)
{
    uint8_t buf[2];
    memset(buf, 0, sizeof(uint8_t) * 2);                                        /* clear the buffer */
    if (iicRead(addr_, reg, (uint8_t *)buf,2))       /* read data */
    {
        *data = (uint16_t)(((uint16_t)buf[0] << 8) | buf[1]);                   /* set data */
        return true;                                                               /* success return 0 */
    }
    else
    {
        return false;                                                               /* return error */
    }                                                  
}
    
bool ADCDevice::ads1115Write(uint8_t reg, uint16_t data){
    uint8_t buf[2];

    buf[0] = (data >> 8) & 0xFF;                                            /* set MSB */
    buf[1] = data & 0xFF;                                                   /* set LSB */
    if (iicWrite(addr_, reg, (uint8_t *)buf, 2))   /* write data */
    {
        return 1;                                                           /* return error */
    }
    else
    {
        return 0;                                                           /* success return 0 */
    }
}

bool ADCDevice::iicRead(uint8_t addr,uint8_t reg, uint8_t *buf, uint16_t len)
{
    int fd = fd_;
    struct i2c_rdwr_ioctl_data i2c_rdwr_data;
    struct i2c_msg msgs[2];
    
    memset(&i2c_rdwr_data, 0, sizeof(struct i2c_rdwr_ioctl_data));
    
    memset(msgs, 0, sizeof(struct i2c_msg) * 2);
    
    msgs[0].addr = addr >> 1;
    msgs[0].flags = 0;
    msgs[0].buf = &reg;
    msgs[0].len = 1;
    msgs[1].addr = addr >> 1;
    msgs[1].flags = I2C_M_RD;
    msgs[1].buf = buf;
    msgs[1].len = len;
    i2c_rdwr_data.msgs = msgs;
    i2c_rdwr_data.nmsgs = 2;
    if (ioctl(fd, I2C_RDWR, &i2c_rdwr_data) < 0)
    {
        CLOG_WARN()<< "I2C Write ERROR";
        return false;
    }
    return true;
}

bool ADCDevice::iicWrite(uint8_t addr,uint8_t reg, uint8_t *buf, uint16_t len)
{   
    int fd = fd_;
    struct i2c_rdwr_ioctl_data i2c_rdwr_data;
    struct i2c_msg msgs[1];
    uint8_t buf_send[len + 1];
    
    /* clear ioctl data */
    memset(&i2c_rdwr_data, 0, sizeof(struct i2c_rdwr_ioctl_data));
    
    /* clear msgs data */
    memset(msgs, 0, sizeof(struct i2c_msg) * 1);
    
    /* clear sent buf */
    memset(buf_send, 0, sizeof(uint8_t) * (len + 1));
    
    /* set the param */
    msgs[0].addr = addr >> 1;
    msgs[0].flags = 0;
    buf_send[0] = reg;
    memcpy(&buf_send[1], buf, len);
    msgs[0].buf = buf_send;
    msgs[0].len = len + 1;
    i2c_rdwr_data.msgs = msgs;
    i2c_rdwr_data.nmsgs = 1;
    /* transmit */
    if (ioctl(fd, I2C_RDWR, &i2c_rdwr_data) < 0)
    {
        CLOG_WARN()<< "I2C Write ERROR";
        return false;
    }
    return true;
}

ADCDevice::~ADCDevice()
{

}
