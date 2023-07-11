/**
 * @file DirverManager.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  外设设备管理器
 * @version 0.1
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
#pragma once

#include <memory>
#include <mutex>
#include <vector>

#include "SerialDriver.h"
#include "SimpleSigleton.h"
#include <iostream>
#include "CLog.h"

SERIAL_DRIVER_CLASS(Serial1);
SERIAL_DRIVER_CLASS(Serial2);
class DriverManager {
  DISALLOW_COPY_AND_ASSIGN(DriverManager)
  
 public:
  DriverManager();
  virtual ~DriverManager();
  //串口1对外接口
  std::shared_ptr<Serial1>& serial1() { return _serial1; }
  //串口2对外接口
  std::shared_ptr<Serial2>& serial2() { return _serial2; }

 private:
  std::shared_ptr<Serial1> _serial1;
  std::shared_ptr<Serial2> _serial2;
};
