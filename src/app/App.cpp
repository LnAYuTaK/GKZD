
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
#include "json.h"
using namespace Json;

/***********************************************************/
Application  *Application::_app = nullptr; 
Application::Application(/* args */)
   :_netWorkMgr(std::make_shared<NetWorkManager>())
   ,_driverMgr(std::make_shared<DriverManager>())
{
   //注意顺序
   _app        =  this;
}
/***********************************************************/
Application* app(void)
{
  return Application::_app;
}
/***********************************************************/
Application::~Application()
{

}
/***********************************************************/
void Application::Init(/* args */)
{
   //Start
   CLOG_INFO("%s","Init App");
















}
/***********************************************************/
void Application::Start()
{
   CLOG_INFO("%s","Start App");
}
/***********************************************************/








