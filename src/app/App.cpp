
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
#include <thread>
#include <chrono>

void on_cloud_message(const std::string& data)
{
    std::cout<<"received data is: "<<data<<std::endl;
}
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
   // _threadPool =  new ThreadPool(MAX_THREAD_NUM);
   _serialMgr  =  new SerialManager();
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
   // cloud::mqtt_client g_client;                         //定义一个mqtt客户端
   // std::cout << "[CLOUD] listen starting"<<std::endl;
   // g_client.set_message_handler(on_cloud_message);      //开启mqtt clinet监听消息，消息处理函数为on_cloud_message
   // while(1)
   // {
   //    std::cout << "运行中..."<<std::endl;
   //    std::this_thread::sleep_for(std::chrono::seconds(10));
   //    g_client.send("online...");  // 确保与mqtt broker server建立连接之后再publish!!!
   // }
}
/***********************************************************/








