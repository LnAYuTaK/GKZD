/**
 * @file BufferPtr.h
 * @brief 外设设备基类
 * @version 0.1
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */

#pragma once

class IODevice{
 public:

  enum DriverType { SerialType, 
                    ADCDeviceType, 
                    SpiType, 
                    GPIOType 
  };
  IODevice(/* args */){;}
  virtual DriverType type() const = 0;
  virtual bool open() = 0 ;
  virtual void close() =0 ;
  virtual ~IODevice() {;}

};


