/**
 * @file BufferPtr.h
 * @brief 外设设备基类
 * @version 0.1
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */

#pragma once

enum DriverType { SerialType, I2cType, SpiType, GPIOType };

class IODevice{

 public:
  IODevice(/* args */){;}
  virtual DriverType type() const = 0;
  virtual ~IODevice() {;}

};


