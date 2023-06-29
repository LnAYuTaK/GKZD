#include "App.h"
#define MAX_THREAD 5
#define DB_FILE "test.db"

#define THREAD_SLEEP_MS(x) do{std::this_thread::sleep_for \
                           (std::chrono::milliseconds(x));}\
                           while(0)  
/***********************************************************/
//实例化模块
Application::Application(/* args */)
   :_threadPool(std::make_shared<ThreadPool>(MAX_THREAD))
   ,_blockerMgr(std::make_shared<BlockerManager>())
   ,_netWorkMgr(std::make_shared<NetWorkManager>())
   ,_driverMgr(std::make_shared<DriverManager>())
   #ifdef  DATABASE_TEST
   ,_dataBase(DB_FILE)
   #endif
{
   
}
/***********************************************************/
Application* app(void)
{
  return Application::Instance();
}
/***********************************************************/
Application::~Application()
{
}
/***********************************************************/
#ifdef NETWORK_TEST
//处理回调信息 如果不是耗时操作不需要开启线程 
//这里模拟如果耗时操作
void HandleServer(const std::shared_ptr<Bytes>&msg)
{
   auto function =[&msg](){
		std::cout<<"ThreadID:  "<<std::this_thread::get_id() <<" ServerMSG:  "<< msg->ptr()<<std::endl;
	};
   app()->TPool()->submit(function);
}
void HandleClient(const std::shared_ptr<Bytes>&msg)
{
   auto function =[&msg](){
		std::cout<<"ThreadID:  "<<std::this_thread::get_id() <<" ClientMSG:  "<< msg->ptr()<<std::endl;
	};
   app()->TPool()->submit(function);
}
#endif
/***********************************************************/
void Application::init(/* args */)
{
//网络模块初始化  订阅客户端服务器的接收消息
#ifdef NETWORK_TEST 
   auto NetWorkMgr = app()->NetWorkMgr();
   auto BlockerMgr = app()->BlcokerMgr();
   auto Poll       = app()->TPool();
   //订阅消息 ---执行回调
   BlockerMgr->Subscribe<Bytes>("TCPSever",1, "HandleServer",HandleServer);
   BlockerMgr->Subscribe<Bytes>("TCPClient",1,"HandleClient",HandleClient);
   //重连线程函数 自动检测服务器客户端状态重连
   auto reConnect = [=]() {
      while(1)
      {
         if(NetWorkMgr->Server()->GetState()==EnServiceState::SS_STOPPED)
         {
            NetWorkMgr->Server()->Start(SERVER_IP,PORT);
         }
         if((!(NetWorkMgr->Client()->IsConnected())) || 
           NetWorkMgr->Client()->GetState()==EnServiceState::SS_STOPPED)
         {
            NetWorkMgr->Client()->Start(CLIENT_IP,PORT);
         }
      }
   };
   //客户端服务器开启
   NetWorkMgr->Server()->Start(SERVER_IP,PORT);
   NetWorkMgr->Client()->Start(CLIENT_IP,PORT);
   //开启重连线程
   Poll->submit(reConnect);
   #endif
}
/***********************************************************/
void Application::start()
{
  
  //日志测试
   #ifdef CLOG_TEST
   while (1)
   {
      static int a ;
      a  =a +1;
      CLOG_INFO() <<"Times: "  <<  a <<  << " " <<'c';
      CLOG_INFO_FMT("Times: %d",a);
      CLOG_ERROR() <<"Times: "  <<  a << " test" << 1.1;
      CLOG_WARN() <<"Times: "  <<  a ;
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
   }
   #endif
   //数据库创建写入测试
   #ifdef  DATABASE_TEST
   int ret = _dataBase.exec("CREATE TABLE IF NOT EXISTS table1 (test1 INTEGER PRIMARY KEY UNIQUE,test2 INTEGER UNIQUE);");
   ret = _dataBase.exec("INSERT INTO table1 (test1, test2) VALUES (1, 30);");
   #endif
}
/***********************************************************/







