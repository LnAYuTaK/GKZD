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
//user
#include "CLOG.h"
#include "SimpleSigleton.h"
#include "ThreadPool.h"
#include "NetWorkManager.h"
#include "DriverManager.h"
#include "BlockerManager.h"
#include "FileHelper.h"
#include "BufferPtr.h"
#include "Database.h"

//Test def 
// #define  NETWORK_TEST
// #define  DATABASE_TEST

class Application
{
    //单例
    DECLARE_SINGLETON(Application)
    using ThreadPoolShardPtr =      std::shared_ptr<ThreadPool>;
    using BlockerMgrShardPtr =      std::shared_ptr<BlockerManager>;
    using DriverMgrShardPtr  =      std::shared_ptr<DriverManager>;
    using NetWorkMgrShardPtr =      std::shared_ptr<NetWorkManager>;
public:
   
    ~Application();

    
    void init();
    void start();
    //外部接口
    
    //线程池
    ThreadPoolShardPtr     &      TPool               (){return this->_threadPool;}
    //事件发布订阅管理器
    BlockerMgrShardPtr     &      BlcokerMgr          (){return this->_blockerMgr;}
    //外设设备管理器
    DriverMgrShardPtr      &      DriverMgr           (){return this->_driverMgr;}
    //网络通信管理器
    NetWorkMgrShardPtr     &      NetWorkMgr          (){return this->_netWorkMgr;}

private:
    //内部资源
    ThreadPoolShardPtr        _threadPool;
    BlockerMgrShardPtr        _blockerMgr;
    NetWorkMgrShardPtr        _netWorkMgr;
    DriverMgrShardPtr         _driverMgr;
    //TUDO 数据库模块
    Database                  _dataBase;
};

//全局单例接口
Application * app();











