/**
 * @file App.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  应用程序Application (全局单例)
 * @version 0.1
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
#pragma once
// std
#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
// user
#include "Bytes.h"
#include "CLog.h"
#include "FileHelper.h"
#include "MacroDef.h"
#include "ThreadPool.h"
#include "IOControl.h"
//app

// Test def
// #define IO_TEST
class NetWorkManager;
class ParaManager;
class BlockerManager;
class DriverManager;
class NetWorkManager;

#define MAX_THREAD 5
#define DB_FILE "test.db"
// #define MQTT_TEST
// #define NETWORK_TEST
//#define  DATABASE_TEST
class Application {
  //单例
  DECLARE_SINGLETON(Application)

  using ParaMgrShardPtr    = std::shared_ptr<ParaManager>;
  using BlockerMgrShardPtr = std::shared_ptr<BlockerManager>;
  using DriverMgrShardPtr  = std::shared_ptr<DriverManager>;
  using NetWorkMgrShardPtr = std::shared_ptr<NetWorkManager>;

 public:
  ~Application();
  //资源初始化
  void init();
  //开启系统任务
  void start();
  ParaMgrShardPtr& ParaMgr() { return this->_paraMgr; }
  //事件发布订阅管理器
  BlockerMgrShardPtr& BlcokerMgr() { return this->_blockerMgr; }
  //外设设备管理器
  DriverMgrShardPtr& DriverMgr() { return this->_driverMgr; }
  //网络通信管理器
  NetWorkMgrShardPtr& NetWorkMgr() { return this->_netWorkMgr; }

 private:
  //内部资源
  ParaMgrShardPtr    _paraMgr;
  BlockerMgrShardPtr _blockerMgr;
  NetWorkMgrShardPtr _netWorkMgr;
  DriverMgrShardPtr  _driverMgr;

};

//全局单例接口
Application* app();
