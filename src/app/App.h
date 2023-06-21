#pragma once 
#include <thread>
#include <chrono>
#include <memory>
//std
#include <iostream>
#include <string>
//user
#include "SimpleSigleton.h"
#include "CLOG.h"
#include "NetWorkManager.h"
#include "ThreadPool.h"
#include "DriverManager.h"
#include "BlockerManager.h"
class DriverManager;
class NetWorkManager;
class Application
{
    DISALLOW_COPY_AND_ASSIGN(Application);

    using DriverMgr_Ptr  = std::shared_ptr<DriverManager>;
    using NetWorkMgr_Ptr = std::shared_ptr<NetWorkManager>;
    using BlockerMgr_Ptr = std::shared_ptr<BlockerManager>;

public:
    Application();
    ~Application();

    void Init();
    void Start();

    static Application *_app;

   DriverMgr_Ptr &  getDriverMgr  ()  {return this->_driverMgr;}
   NetWorkMgr_Ptr & getNetWorkMgr ()  {return this->_netWorkMgr;}
   BlockerMgr_Ptr   getBlockMgr   ()  {return BlockerManager::Instance();}
   //TUDO

   //ParaMgr_Ptr

private:
   NetWorkMgr_Ptr _netWorkMgr;
   DriverMgr_Ptr  _driverMgr;
};

Application * app();











