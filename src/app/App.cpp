
#include "App.h"
#include "NetWorkManager.h"
#include "BlockerManager.h"
#include "Database.h"
#include "DriverManager.h"
#include "ParaManager.h"

/***********************************************************/
//实例化模块
Application::Application(/* args */)
    : _paraMgr(std::make_shared<ParaManager>()),
      // _threadPool(std::make_shared<ThreadPool>(MAX_THREAD)),
      _blockerMgr(std::make_shared<BlockerManager>()),
      _netWorkMgr(std::make_shared<NetWorkManager>()),
      _driverMgr(std::make_shared<DriverManager>())
#ifdef DATABASE_TEST
      ,
      _dataBase(DB_FILE)
#endif
{
}
/***********************************************************/
Application* app(void) { return Application::Instance(); }
/***********************************************************/
Application::~Application() {}
/***********************************************************/
//处理回调信息 如果不是耗时操作不需要开启线程
//这里模拟如果耗时操作
#ifdef NETWORK_TEST
void HandleServer(const std::shared_ptr<Bytes>& msg) {
  auto function = [&msg]() {
    std::cout << "ThreadID:  " << std::this_thread::get_id()
              << " ServerMSG:  " << msg->ptr() << std::endl;
  };
  ThreadPool::Instance()->submit(function);
}
void HandleClient(const std::shared_ptr<Bytes>& msg) {
  auto function = [&msg]() {
    std::cout << "ThreadID:  " << std::this_thread::get_id()
              << " ClientMSG:  " << msg->ptr() << std::endl;
  };
  ThreadPool::Instance()->submit(function);
}
#endif
/***********************************************************/
void Application::init(/* args */) {
#ifdef IO_TEST
  IOControl::setValue(IOControl::Relay8, IOControl::GPIO_SET);
  IOControl::setValue(IOControl::Relay8, IOControl::GPIO_RESET);
#endif
#ifdef NETWORK_TEST
  //网络模块初始化
  auto NetWorkMgr = app()->NetWorkMgr();
  auto NetConf = app()->ParaMgr()->netConf().obj();
  auto ClientHost = NetConf.clienthost().c_str();
  auto ServerHost = NetConf.serverhost().c_str();
  auto ClientPort = NetConf.tcpclientport();
  auto ServerPort = NetConf.tcpserverport();
  //客户端服务器开启
  NetWorkMgr->Server()->Start(ServerHost, ServerPort);
  NetWorkMgr->Client()->Start(ClientHost, ClientPort);
//订阅消息 ---执行回调
#endif
#ifdef MQTT_TEST
  NetWorkMgr->Mqtt()->Start(NetConf.mqttserverurl(), NetConf.mqttclientname());
  auto opts = mqtt::connect_options_builder()
                  .mqtt_version(MQTTVERSION_5)
                  .clean_start(true)
                  .finalize();
  opts.set_user_name(NetConf.mqttname());
  opts.set_password(NetConf.mqttpassword());
  NetWorkMgr->Mqtt()->Connect(opts);
  THREAD_SLEEP_MS(2000);
#endif
}
/***********************************************************/
void Application::start() {
#ifdef NETWORK_TEST
  auto NetConf = app()->ParaMgr()->netConf().obj();
  auto NetWorkMgr = app()->NetWorkMgr();
  auto BlockerMgr = app()->BlcokerMgr();

  //重连线程函数 自动检测服务器客户端状态重连
  auto reConnect = [=]() {
    while (1) {
#ifdef MQTT_TEST
      if (!(NetWorkMgr->Mqtt()->isConnected())) {
        CLOG_WARN() << "MQTT Reconnect";
        NetWorkMgr->Mqtt()->reConnect();
      }
#endif  // MQTT_TEST
      if (NetWorkMgr->Server()->GetState() == EnServiceState::SS_STOPPED) {
        CLOG_WARN() << "TCPServer Reconnect";
        NetWorkMgr->Server()->Start(NetConf.serverhost().c_str(),
                                    NetConf.tcpserverport());
      }
      if ((!(NetWorkMgr->Client()->IsConnected())) ||
          NetWorkMgr->Client()->GetState() == EnServiceState::SS_STOPPED) {
        CLOG_WARN() << "TCPClient Reconnect";
        NetWorkMgr->Client()->Start(NetConf.serverhost().c_str(),
                                    NetConf.tcpclientport());
      }
    }
  };
  //开启重连线程
  ThreadPool::Instance()->submit(reConnect);
  // Poll->submit(reConnect);
  BlockerMgr->Subscribe<Bytes>("TCPSever", 1, "HandleServer", HandleServer);
  BlockerMgr->Subscribe<Bytes>("TCPClient", 1, "HandleClient", HandleClient);
#endif  // NETWORK_TEST

 auto netConfs = app()->ParaMgr()->netConf().obj();

 CLOG_INFO() << netConfs->mqttclientname();
 netConfs->set_mqttclientname("123123123123123");

 CLOG_INFO() << netConfs->mqttclientname();
 app()->ParaMgr()->netConf().saveConf();


//数据库创建写入测试
#ifdef DATABASE_TEST
  int ret = _dataBase.exec(
      "CREATE TABLE IF NOT EXISTS table1 (test1 INTEGER PRIMARY KEY "
      "UNIQUE,test2 INTEGER UNIQUE);");
  ret = _dataBase.exec("INSERT INTO table1 (test1, test2) VALUES (1, 30);");
#endif  // DATABASE_TEST
}
/***********************************************************/
