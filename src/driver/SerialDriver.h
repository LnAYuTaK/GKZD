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

    DriverType type() const override{return this->_type;}

   
    int readData(void *data, int size){
        return _port->readData(data,size);
    }

    int writeData(const void *data, int size){
       return  _port->writeData(data,size);
    }

    bool open(){
       return  _port->open();
    }

    void close(){
        _port->close();
    }

private:
    CSerialPort *    _port     = nullptr;
    SerialListener * _listener = nullptr;
    DriverType  _type ;
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

#define SERIAL_DRIVER_CLASS(classname)         \
    class classname   :public SerialDirver     \
    {                                          \
    private:                                   \
    public:                                    \
        classname(){;}                         \
        ~classname(){;}                        \
        void onReadEvent(const char *portName, unsigned int readBufferLen)override; \
    }; 







