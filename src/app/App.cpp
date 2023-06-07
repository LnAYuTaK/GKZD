
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

#define  MAX_THREAD_NUM 4
/***********************************************************/
Application  *Application::_app = nullptr; 
Application::Application(/* args */)
   :_threadPool(nullptr)
   ,_serialMgr(nullptr)
   ,_netMgr(nullptr)
{
   //注意顺序
   _app        =  this;
   //_threadPool =  new ThreadPool(MAX_THREAD_NUM);
   //_serialMgr  =  new SerialManager();
   _netMgr     =  new NetWorkManager();
}
/***********************************************************/
Application* app(void)
{
  return Application::_app;
}
/***********************************************************/
Application::~Application()
{
   // _threadPool->shutdown();
   // delete _serialMgr;
   // delete _netMgr;
   // delete _threadPool;
   
   // _threadPool = nullptr;
   // _serialMgr  = nullptr;
   // _netMgr     = nullptr;
   // _app        = nullptr;
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








