/**
 * @file NetWorkManager.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  网络通信管理器 (管理所有网络服务器客户端等网络接口)
 * @version 0.1
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
#pragma once

#include <iostream>
#include <memory>
// app
#include "App.h"
// common
#include "CLog.h"
#include "MacroDef.h"
// net
#include "MqttClient.h"
#include "TCPClient.h"
#include "TCPServer.h"

class NetWorkManager {
  DISALLOW_COPY_AND_ASSIGN(NetWorkManager)
 public:
  NetWorkManager(/* args */);
  virtual ~NetWorkManager();

  CTcpPullServerPtr& Server() { return _tcpServer; }
  CTcpPullClientPtr& Client() { return _tcpClient; }
  MQTTClientPtr& Mqtt() { return _mqttClient; }

 private:
  // MQTT
  MQTTClientPtr _mqttClient;
  // CLient
  TCPClientListener _clisterner;
  CTcpPullClientPtr _tcpClient;
  // Server
  TCPServerListener _slistener;
  CTcpPullServerPtr _tcpServer;
};
