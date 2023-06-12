#pragma once 
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include <thread>
#include <math.h>
#include <sys/types.h>
#include <dirent.h>
#include <chrono>
#include <memory>
//std
#include <iostream>
#include <string>
//user
#include "mqttClientCloud.h"
#include "CLOG.h"
#include "NetWorkManager.h"
#include "ThreadPool.h"
#include "DriverManager.h"
class DriverManager;
class NetWorkManager;
class Application
{
public:
    Application();
    ~Application();

    void Init();
    void Start();
    static Application* _app;

    NetWorkManager * newMgr     (){return this->_netMgr;}
    ThreadPool *     threadPool (){return this->_threadPool;}
    DriverManager *  driverMgr  (){return this->_driverMgr;}

private:
   DriverManager *   _driverMgr;
   ThreadPool     *  _threadPool;
   NetWorkManager *  _netMgr;
   mqtt_client g_client;
};





Application * app();











