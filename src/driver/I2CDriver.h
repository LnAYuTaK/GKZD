#include "DriverBase.h"
class I2CDriver :public DriverBase
{
private:
    /* data */
public:
    I2CDriver (/* args */);
    ~I2CDriver ()override;

    DriverType type() const override {return _type;}
    
    DriverType _type;
};

