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
enum CLOG_LEVEL
{
    CLOG_LEVEL_INFO,
    CLOG_LEVEL_WARNING,
    CLOG_LEVEL_ERROR
};
class CLOG
{
    DECLARE_SINGLETON(CLOG)  
public:

    ~CLOG();
    //设置当前文件输出文件
    void EnableToFile(std::string &fileName){ 
        this->_ToFile = true; 
        //TODU  Check File Path  
        this->_LogFileName = std::move(fileName);
    }
    void DisableToFile()      {this->_ToFile     = false;}
    void EnableToTerminal()   {this->_ToTerminal = true;}
    void DisableToTerminal()  {this->_ToTerminal = false;}
    
    void  CLOGPrint(CLOG_LEVEL nLevel,const char* pcFunc, const int& line, const char* fmt, ...);

private:
    unsigned long long GetCurrentThreadId();
    char* GetCurrentTime();
    constexpr   void writeLogLevel(char * buffer,CLOG_LEVEL nLevel);

    std::string         _LogFileName;       //日志文件名
    bool                    _ToFile;                          //是否允许写入文件
    bool                   _ToTerminal;               //是否允许控制台
    CLOG_LEVEL  _LOGLevel;       //日志级别
    std::mutex       _WriteMtx;              //写锁
    std::FILE*         _LogFile;                   //日志文件
    int                        _MxLogBufferSize;       //最大输出日志长度
};
#define CLOG_INFO(fmt, args...)      CLOG::Instance()->CLOGPrint(CLOG_LEVEL_INFO, __FUNCTION__ , __LINE__,fmt,##args)
#define CLOG_WARNING(fmt,  args...)  CLOG::Instance()->CLOGPrint(CLOG_LEVEL_WARNING,__FUNCTION__ , __LINE__,fmt,##args)
#define CLOG_ERROR(fmt,  args...)    CLOG::Instance()->CLOGPrint(CLOG_LEVEL_ERROR, __FUNCTION__ , __LINE__,fmt,##args)
