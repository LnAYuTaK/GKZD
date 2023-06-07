#include "CLOG.h"
#include <stdarg.h>
#include <fstream>
#include <thread>
#include <sys/time.h>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <cstdarg>
#include <memory.h>
thread_local char _timebuf[64] = {0x00};
CLOG::CLOG()
    : _ToFile(false)
    , _ToTerminal(true)
    , _LogFileName(std::string(""))
    , _MxLogBufferSize(256)
    , _LOGLevel(CLOG_LEVEL_INFO)
{
  
}
/***********************************************************/
CLOG::~CLOG()
{
}
/***********************************************************/
char *CLOG::GetCurrentTime()
{
  time_t t = time(nullptr);
  struct tm *now = localtime(&t);
  strftime(_timebuf, sizeof(_timebuf),
           "%Y.%m.%d-%H:%M:%S",
           now);
  now = nullptr;
  return _timebuf;
}
/***********************************************************/
unsigned long long CLOG::GetCurrentThreadId()
{
  std::ostringstream oss;
  oss << std::this_thread::get_id();
  std::string stid = oss.str();
  unsigned long long tid = stoull(stid);
  return tid;
}
/***********************************************************/
void CLOG::CLOGPrint(CLOG_LEVEL nLevel, const char *pcFunc, const int &line, const char *fmt, ...)
{
  std::lock_guard<std::mutex> lock(_WriteMtx);
  char buffer[_MxLogBufferSize];
  memset(buffer, 0, _MxLogBufferSize);
  char levelBuffer[32];
  memset(levelBuffer, 0, 32);
  switch (nLevel)
  {
  case CLOG_LEVEL_INFO:
    sprintf(levelBuffer, "\033[0m\033[1;32m%s\033[0m", "INFO");
    break;
  case CLOG_LEVEL_WARNING:
    sprintf(levelBuffer, "\033[0m\033[1;33m%s\033[0m", "WARING");
    break;
  case CLOG_LEVEL_ERROR:
    sprintf(levelBuffer, "\033[0m\033[1;31m%s\033[0m", "ERROR ");
    break;
  default:
    sprintf(levelBuffer, "\033[0m\033[1;34m%s\033[0m", "UNKNOW");
    break;
  }
  int n = sprintf(buffer, 
                  "[%s]"
                  // "[THREAD:%llu]"
                  "[%s]"
                  "[%s] [%d] ",
                  GetCurrentTime(),
                  // GetCurrentThreadId(),
                  levelBuffer,
                  pcFunc,
                  line);

  va_list vap;
  va_start(vap, fmt);
  vsnprintf(buffer + n,_MxLogBufferSize-n, fmt, vap);
  va_end(vap);
  // if(_ToFile)
  // {
  //   ofstream fout(log()->_LogFileName,ios::app);
  //   fout<<buffer;
  //   fout<< "\0\n";
  //   fout.close();
  // }
  if(_ToTerminal)
  {
    fprintf(stdout,"%s\n",buffer);
    fflush(stdout);
  }
}
