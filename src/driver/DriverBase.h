#pragma once
enum DriverType {
    SerialType, 
    I2cType, 
    SpiType
}; 

class DriverBase
{
private:
    /* data */
public:
    virtual DriverType type() const = 0 ;
    virtual ~DriverBase(){;}
};



