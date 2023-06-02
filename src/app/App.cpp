
/**
 * @file App.cpp
 * @author LnAYuTaK (807874484@qq.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "App.h"

/***********************************************************/
Application  *Application::_app = nullptr; 
Application::Application(/* args */)
 :_serial(nullptr)
{
   //注意顺序
   _app    = this;
   _serial = new CSerialPort();
}
/***********************************************************/
Application* app(void)
{
  return Application::_app;
}
/***********************************************************/
Application::~Application()
{
   _app =nullptr;
}
/***********************************************************/
void Application::Init(/* args */)
{
   // //Serial Init初始化
   // _serial->init(UART2,
   //              itas109::BaudRate115200, // baudrate
   //              itas109::ParityNone,     // parity
   //              itas109::DataBits8,      // data bit
   //              itas109::StopOne,        // stop bit
   //              itas109::FlowNone,       // flow
   //              4096  
   // );
   // _serial->setReadIntervalTimeout(0); 
   // //Link Mavlink Control 交付给SerialHandle类处理
   // _serial->connectReadEvent(_mavlinkhandle);
}
/***********************************************************/
void Application::Start()
{
   // //开启mavlink 串口接收线程 检测串口数据执行操作
   // _serial->open();
   // if(!(_serial->isOpen()))
   // {
   //    LOG_ERROR("%s","Serial OPEN ERROR");
   //    return;
   // }
   // else
   // {
   //    LOG_INFO("%s [%s]","OPEN SERIAL OK",_serial->getPortName());
   // }
}
/***********************************************************/








