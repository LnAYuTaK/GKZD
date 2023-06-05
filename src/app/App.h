#pragma once 
#include <unistd.h>
#include <signal.h>
#include <semaphore.h>
#include <thread>
#include <math.h>
#include <sys/types.h>
#include <dirent.h>
#include "CLOG.h"
#include "NetWorkManager.h"
#include "SerialManager.h"
class SerialManager;
class NetWorkManager;
class Application
{
public:
    Application();
    ~Application();
    //
    void Init();
    void Start();
    static Application* _app;
private:
   SerialManager * serialMgr;
   NetWorkManager * netMgr;
};
Application * app();











