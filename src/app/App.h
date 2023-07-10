/**
 * @file App.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  应用程序Application (全局单例)
 * @version 0.1
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
#pragma once 
//std
#include <thread>
#include <chrono>
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
//user
#include "CLOG.h"
#include "macro.h"
#include "Bytes.h"
#include "SimpleSigleton.h"
#include "ThreadPool.h"
#include "FileHelper.h"
#include "Bytes.h"

#include "NetWorkManager.h"
#include "DriverManager.h"
#include "BlockerManager.h"
#include "Database.h"
#include "ParaManager.h"

//Test def 
// #define IO_TEST 
#define MAX_THREAD 5
#define DB_FILE "test.db"
#define MQTT_TEST
#define NETWORK_TEST
//#define  CLOG_TEST
//#define  DATABASE_TEST
class Application
{
    //单例
    DECLARE_SINGLETON(Application)

    using ParaMgrShardPtr    =  std::shared_ptr<ParaManager>;
    using ThreadPoolShardPtr =  std::shared_ptr<ThreadPool>;
    using BlockerMgrShardPtr =  std::shared_ptr<BlockerManager>;
    using DriverMgrShardPtr  =  std::shared_ptr<DriverManager>;
    using NetWorkMgrShardPtr =  std::shared_ptr<NetWorkManager>;

public:
    ~Application();
    //资源初始化
    void init();
    //开启系统任务
    void start();
    ParaMgrShardPtr      &   ParaMgr     (){return this->_paraMgr;}
    //线程池
    ThreadPoolShardPtr   &   TPool       (){return this->_threadPool;}
    //事件发布订阅管理器
    BlockerMgrShardPtr   &   BlcokerMgr  (){return this->_blockerMgr;}
    //外设设备管理器
    DriverMgrShardPtr    &   DriverMgr   (){return this->_driverMgr;}
    //网络通信管理器
    NetWorkMgrShardPtr   &   NetWorkMgr  (){return this->_netWorkMgr;}
private:
    //内部资源
    ParaMgrShardPtr           _paraMgr; 
    ThreadPoolShardPtr        _threadPool;
    BlockerMgrShardPtr        _blockerMgr;
    NetWorkMgrShardPtr        _netWorkMgr;
    DriverMgrShardPtr         _driverMgr;
    
    // ParaManager               mgr;
    //TUDO 数据库模块
    #ifdef DATABASE_TEST
    Database                  _dataBase;
    #endif
};

//全局单例接口
Application * app();











