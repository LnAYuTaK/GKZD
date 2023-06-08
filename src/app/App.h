#pragma once 
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include <thread>
#include <math.h>
#include <sys/types.h>
#include <dirent.h>
#include "CLOG.h"
#include "NetWorkManager.h"
#include "SerialManager.h"
#include "ThreadPool.h"
#include <iostream>
#include <string>

class SerialManager;
class NetWorkManager;
class Application
{
public:
    Application();
    ~Application();
    //
    void Init();
    void Start();
    static Application* _app;

    NetWorkManager * newMgr     (){return this->_netMgr;}
    SerialManager *  serialMgr  (){return this->_serialMgr;}
    ThreadPool *     threadPool (){return this->_threadPool;}
private:
   ThreadPool     *  _threadPool;
   SerialManager  *  _serialMgr;
   NetWorkManager *  _netMgr;
};





Application * app();











