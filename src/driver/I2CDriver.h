#include "DriverBase.h"
class I2CDriver :public DriverBase
{
private:
    /* data */
public:
    I2CDriver (/* args */){};
    ~I2CDriver ()override;
};

I2CDriver ::~I2CDriver ()
{
}
