/**
 * @file CLOG.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief 日志模块 
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 
#include <string>
#include <iostream>
#include <mutex>
#include "SimpleSigleton.h"
#include <cstdio>
#include "LogStream.h"
#include <fstream>

class CLOG
{
  DECLARE_SINGLETON(CLOG)  
public:

  enum class CLOG_LEVEL
  {
    CLOG_LEVEL_DEBUG,
    CLOG_LEVEL_INFO,
    CLOG_LEVEL_WARN,
    CLOG_LEVEL_ERROR,
  };

  static constexpr const char* LogLevelName[4] =
  {
    " DEBUG",
    " INFO ",
    " WARN ",
    " ERROR"
  };
  //Not Used 
  static constexpr const char* LogLevelNameColor[4] =
  {
    " \033[0m\033[1;36mDEBUG\033[0m ",
    " \033[0m\033[1;32mINFO\033[0m  ",
    " \033[0m\033[1;33mWARN\033[0m  ",
    " \033[0m\033[1;31mERROR\033[0m "
  };

  ~CLOG();  

  static unsigned long long GetCurrentThreadId();
  
  static std::string GetCurrentData();
  
  static std::string GetCurrentDateTime();

  static char* GetCurrentTime();
//TUDO
  void  CLOGPrint(CLOG_LEVEL nLevel,const char* pcFunc, const int& line, const char* fmt, ...);
//To File
  inline bool isToFile(){
    return _ToFile;
  }
  
  inline void setToFile(bool select){
      this->_ToFile = select;
  }
//
  class LogMsg
  {
  public:
    //DEBUG INFO 
    LogMsg(CLOG_LEVEL nLevel,const char* pcFunc,const int& line)
    {
      std::lock_guard<std::mutex> lock(_mtx);
      _stream << "["<< CLOG::GetCurrentDateTime()  << "]"
              << "["<< LogLevelName[(int)nLevel]   << "]" 
              << "["<< pcFunc                      << "]"
              << "["<< line                        << "]"; 
    }
    //WARN ERROR
    LogMsg(CLOG_LEVEL nLevel,const char* pcFunc,const char *file,const int& line)
    {
      std::lock_guard<std::mutex> lock(_mtx);
      _stream << "["<< CLOG::GetCurrentDateTime()  << "]"
              << "["<< LogLevelName[(int)nLevel]   << "]" 
              << "["<< pcFunc                      << "]"
              << "["<< file                        << "]"
              << "["<< line                        << "]"; 
    }
    ~LogMsg()
    {
      std::lock_guard<std::mutex> lock(_mtx);
      if(CLOG::Instance()->isToFile())
      {
        std::fstream f;
        std::string  s = CLOG::GetCurrentData()+".log";
        f.open(s, std::fstream::out | std::fstream::app);
        f <<_stream.buffer().data()<<std::endl;
        if(f.is_open())
        {
          f.flush();
          f.close(); 
        }
      }
      fprintf(stdout,"%s\n",_stream.buffer().data());
      fflush(stdout);
    }
    LogStream & stream()
    {
      return _stream;
    }
  private:  
    std::mutex _mtx; 
    LogStream _stream;
  };

private:
//Tudo
    void writeLogLevel(char * buffer,CLOG_LEVEL nLevel);
//-------------------------------
    std::string        _LogFileName;       //日志文件名
    bool               _ToFile;            //是否允许写入文件
    bool               _ToTerminal;        //是否允许控制台
    std::mutex         _WriteMtx;          //写锁
    int                _MxLogBufferSize;   //最大输出日志长度
};

//C Style LOG
#define CLOG_INFO_FMT(fmt, args...)   CLOG::Instance()->CLOGPrint(CLOG::CLOG_LEVEL::CLOG_LEVEL_INFO, __FUNCTION__ , __LINE__,fmt,##args)
#define CLOG_WARN_FMT(fmt,  args...)  CLOG::Instance()->CLOGPrint(CLOG::CLOG_LEVEL::CLOG_LEVEL_WARNING,__FUNCTION__ , __LINE__,fmt,##args)
#define CLOG_ERROR_FMT(fmt,  args...) CLOG::Instance()->CLOGPrint(CLOG::CLOG_LEVEL::CLOG_LEVEL_ERROR, __FUNCTION__ , __LINE__,fmt,##args)
//CPP Style LOG
#define CLOG_DEBUG()  CLOG::LogMsg(CLOG::CLOG_LEVEL::CLOG_LEVEL_DEBUG, __FUNCTION__ , __LINE__).stream()   
#define CLOG_INFO()   CLOG::LogMsg(CLOG::CLOG_LEVEL::CLOG_LEVEL_INFO,  __FUNCTION__ , __LINE__).stream()   
#define CLOG_WARN()   CLOG::LogMsg(CLOG::CLOG_LEVEL::CLOG_LEVEL_WARN,  __FUNCTION__ , __LINE__).stream()  
#define CLOG_ERROR()  CLOG::LogMsg(CLOG::CLOG_LEVEL::CLOG_LEVEL_ERROR, __FUNCTION__ , __LINE__).stream()                                                                                        