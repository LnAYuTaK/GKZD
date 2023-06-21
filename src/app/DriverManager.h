#pragma once 
#include <vector>
#include <mutex>
#include "SerialDriver.h"
#include <memory>
class SerialDirver;
class SerialListener;

SERIAL_DRIVER_CLASS(Serial1);
SERIAL_DRIVER_CLASS(Serial2);

class DriverManager
{

public:
    DriverManager();
    ~DriverManager();
    
    std::shared_ptr<Serial1>& serial1(){return _serial1;}
    std::shared_ptr<Serial2>& serial2(){return _serial2;}

private:
    std::shared_ptr<Serial1> _serial1;
    std::shared_ptr<Serial2> _serial2;

    std::mutex _mt;
    // std::vector<DriverBase *>_driverList;
};





