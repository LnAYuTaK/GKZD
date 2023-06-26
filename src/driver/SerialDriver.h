
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
 
    //读取串口数据 
    int readData(void *data, int size){
        return _port->readData(data,size);
    }
    //写入串口数据
    int writeData(const void *data, int size){
       return  _port->writeData(data,size);
    }
    //打开串口
    bool open(){
       return  _port->open();
    }
    //关闭串口
    void close(){
        _port->close();
    }

private:
    CSerialPort    *    _port    ;
    SerialListener *    _listener;
    DriverType  _type ;
};

class SerialListener :public  CSerialPortListener
{
public:
    SerialListener(CSerialPort *port,SerialDirver* driver);
    void onReadEvent(const char* portName, unsigned int readBufferLen) override;
private:
    CSerialPort  *_port   ;
    SerialDirver *_driver ;
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







