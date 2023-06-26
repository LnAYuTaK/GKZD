

#include "App.h"
#define MAX_THREAD 5
#define DB_FILE "test.db"
/***********************************************************/
//实例化模块
Application::Application(/* args */)
   :_threadPool(std::make_shared<ThreadPool>(MAX_THREAD))
   ,_blockerMgr(std::make_shared<BlockerManager>())
   ,_netWorkMgr(std::make_shared<NetWorkManager>())
   ,_driverMgr(std::make_shared<DriverManager>())
   ,_dataBase(DB_FILE){
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
void Handle(const std::shared_ptr<CBufferPtr>&msg)
{
   //
   auto function =[&msg](){
      std::cout<< "Thread::ID "<<std::this_thread::get_id() << std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout<<"Thread::ID "<<std::this_thread::get_id() <<" Thread::MSG:: "<< msg->Ptr()<<std::endl;
	};
   app()->TPool()->submit(function);
}
#endif
/***********************************************************/
void Application::init(/* args */)
{
   //初始化所有的事件订阅发布
   CLOG_INFO("%s","APP Init");
   #ifdef NETWORK_TEST 
   if(app()->NetWorkMgr()->Server()->Start("192.168.16.232",2456))
   {
      CLOG_INFO("%s","Start TCP OK");
   }
   app()->BlcokerMgr()->Subscribe<CBufferPtr>("Data1",1,"Handle",Handle);
   #endif
}
/***********************************************************/
void Application::start()
{
   CLOG_INFO("%s","App Start");
   #ifdef  DATABASE_TEST
   int ret = _dataBase.exec("CREATE TABLE IF NOT EXISTS table1 (test1 INTEGER PRIMARY KEY UNIQUE,test2 INTEGER UNIQUE);");
   CLOG_INFO("dataBase return %d",ret);
   ret = _dataBase.exec("INSERT INTO table1 (test1, test2) VALUES (1, 30);");
   CLOG_INFO("dataBase return %d",ret);
   #endif
}
/***********************************************************/







