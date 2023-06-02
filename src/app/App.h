#pragma once 
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include <thread>
#include <math.h>
#include <sys/types.h>
#include <dirent.h>

#include "CLOG.h"

#include "SerialPort.h"
#include "SerialPortInfo.h"
class CLOG;
using namespace itas109;
class Application
{
public:
    Application();
    ~Application();
    //
    void Init();
    void Start();
    static Application* _app;
    CLOG  *         LOG()           {return CLOG::Instance();}
    CSerialPort *   Serial()        {return this->_serial;} 
private:

    CSerialPort * _serial;
};
Application * app();











