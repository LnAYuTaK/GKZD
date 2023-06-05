#pragma once 
#include "SerialPort.h"
#include "SerialPortInfo.h"
#include <vector>
using namespace itas109;
class SerialListener :public CSerialPortListener
{

public:
    SerialListener();
    SerialListener(CSerialPort * port1,CSerialPort * port2,CSerialPort * port3);
    ~SerialListener();
    // 响应读取事件
    void onReadEvent(const char *portName, unsigned int readBufferLen)override;
    
private:
    CSerialPort * s_port1;
    CSerialPort * s_port2;
    CSerialPort * s_port3;
    /* data */
};

class SerialManager
{
private:
    /* data */
public:
    SerialManager(/* args */);
    ~SerialManager();
private:
    SerialListener * serialListener;
    
};





