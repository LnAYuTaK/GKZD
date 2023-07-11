/**
 * @file Macro.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  宏定义
 * @version 0.1
 * @date 2023-07-11
 * 
 * 
 */
#pragma once

#include <chrono>
#include <memory>
#include <thread>

//当前线程等待毫秒级
#define THREAD_SLEEP_MS(x)                                     \
  do {                                                         \
    std::this_thread::sleep_for(std::chrono::milliseconds(x)); \
  } while (0)

//当前线程等待微妙级
#define THREAD_SLEEP_MCROS(x)                                  \
  do {                                                         \
    std::this_thread::sleep_for(std::chrono::microseconds(x)); \
  } while (0)
