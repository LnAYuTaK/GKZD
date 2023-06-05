
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
#include "NetWorkManager.h"
#include "SerialManager.h"
#include <memory>
/***********************************************************/
Application  *Application::_app = nullptr; 
Application::Application(/* args */)
{
   //注意顺序
   _app      =  this;
   serialMgr =  new SerialManager();
   netMgr    =  new NetWorkManager();
}
/***********************************************************/
Application* app(void)
{
  return Application::_app;
}
/***********************************************************/
Application::~Application()
{
   delete serialMgr;
   delete netMgr;
   serialMgr = nullptr;
   netMgr    = nullptr;
   _app      = nullptr;
}
/***********************************************************/
void Application::Init(/* args */)
{

   CLOG_INFO("%s","Init App");
}
/***********************************************************/
void Application::Start()
{
   CLOG_INFO("%s","Start App");
}
/***********************************************************/








