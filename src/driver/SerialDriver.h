#pragma once 
#include "SerialPort.h"
#include "SerialPortInfo.h"
#include "DriverBase.h"
#include <functional>
using namespace itas109;
class SerialListener;
class SerialDirver : public DriverBase
{
public:
    SerialDirver();
    ~SerialDirver()override;
    virtual void onReadEvent(const char *portName, unsigned int readBufferLen) = 0 ;
    virtual void init(const char *portName,
              int baudRate = BaudRate9600,
              Parity parity = ParityNone,
              DataBits dataBits = DataBits8,
              StopBits stopbits = StopOne,
              FlowControl flowControl = FlowNone,
              unsigned int readBufferSize = 4096)final;
    virtual bool open()final{
       return  _port->open();
    }
    virtual void close(){
        _port->close();
    }
private:
    CSerialPort *    _port     = nullptr;
    SerialListener * _listener = nullptr;
};

class SerialListener :public  CSerialPortListener
{
public:
    SerialListener(CSerialPort *port,SerialDirver* driver);
    void onReadEvent(const char* portName, unsigned int readBufferLen) override;
private:
    CSerialPort  *_port   = nullptr;
    SerialDirver *_driver = nullptr;
};  

#define SIMPLE_CREATE_SERIAL_DIRVER(classname) \
    class classname   :public SerialDirver     \
    {                                          \
    private:                                   \
    public:                                    \
        classname(){;}            \
        ~classname(){;}                     \
        void onReadEvent(const char *portName, unsigned int readBufferLen)override;\
    }; 

SIMPLE_CREATE_SERIAL_DIRVER(SerialDriver1)





