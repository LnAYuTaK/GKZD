
#include "SerialManager.h"
SerialListener::SerialListener()
    :s_port1(new CSerialPort())
    ,s_port2(new CSerialPort())
    ,s_port3(new CSerialPort())
{ 
    // s_port1->init()
    // s_port1.connectReadEvent(this);

    // s_port2->init()
    // s_port2.connectReadEvent(this);
    
    // s_port3->init()
    //s_port3.connectReadEvent(this);
}
/***********************************************************************************************/
SerialListener::~SerialListener()
{

}
/***********************************************************************************************/
//Handle UartData
void SerialListener::onReadEvent(const char *portName, unsigned int readBufferLen)
{
// //case PortName 

}
/***********************************************************************************************/
SerialManager::SerialManager(/* args */)
    :serialListener(new SerialListener())
{
    //Init Serial
}
/***********************************************************************************************/
SerialManager::~SerialManager()
{
  delete serialListener;
  serialListener = nullptr;
}
/***********************************************************************************************/
