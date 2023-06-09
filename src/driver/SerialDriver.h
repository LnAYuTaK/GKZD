#pragma once 
#include "SerialPort.h"
#include "DriverBase.h"
#include <functional>
using namespace itas109;
class SerialDirver;
class SerialListener :public  CSerialPortListener
{
public:
    SerialListener(CSerialPort *sp,SerialDirver* driver)
    :_port(sp)
    ,_driver(driver){
    };
    virtual void onReadEvent(const char* portName, unsigned int readBufferLen) override 
    {
        if (_driver!=nullptr) 
        {
           _driver->onReadEvent(portName, readBufferLen);
        }
    }
private:
    CSerialPort  *_port   = nullptr;
    SerialDirver *_driver = nullptr;
};  

class SerialDirver : public DriverBase
{
public:
    SerialDirver()
        :listener(&port,this){ 
    }
    ~SerialDirver()override;
    virtual  void onReadEvent(const char *portName, unsigned int readBufferLen) = 0;

    int  write(const void *data, int size){return port.writeData(data,size);}
    int  read(void *data, int size) {return port.readData(data,size);}
//Test 
public:
private:
    CSerialPort    port;
    SerialListener listener;
};





