# 项目概述
## 项目架构
### 项目文件结构
``` DIR
  /bin   //生成应用程序目录
  -   /project  

  /build  //cmake生成中间文件 编译项目目录

  /lib   //第三方动态库
  -  /hpsocket.so
  -  /serialport.so
  
  /src   //项目源文件+头文件目录
  -  /app           //应用层
  -  /common        //公共方法文件(通用方法)
  -  /log           //日志模块
  -  /thirdparty    //第三方库文件

  CMakeLists.txt    //CMAKE

  LICENSE

  README.md
```
### 第三方库
#### 介绍
+ 底层串口采用[CSerialPort](https://github.com/itas109/CSerialPort)串口收发处理 
CSerialPort是一个基于C/C++的轻量级开源跨平台串口类库，可以轻松实现跨平台多操作系统的串口读写，同时还支持C#, Java, Python, Node.js等。
接口全部使用回调函数
+ 底层网络采用[HP-Socket](https://github.com/ldcsaa/HP-Socket)网络处理
HPSocket 是一个小型高性能网络处理框架底层采用epoll作为异步模型可以自动拆包解包处理
+ 
#### 交叉编译第三方库
##### CSerialPort
```console
compile.sh ： 使用 compile.sh shell 脚本自行编译 HP-Socket 库文件。 但是 compile.sh 只编译库文件，不会编译demo可执行文件。

$ cd /HP-Socket/Linux/script
$ ./compile.sh -p arm64
Usage: compile.sh [...O.P.T.I.O.N.S...]
----------------------+-------------------------------------------------
  -d|--with-debug-lib : compile debug libs (default: true)
  -m|--mem-allocator  : memory allocator (default: mimalloc)
                      : (options: mimalloc / jemalloc / system)
  -u|--udp-enabled    : enable UDP components (default: true)
  -t|--http-enabled   : enable HTTP components (default: true)
  -s|--ssl-enabled    : enable SSL components (default: true)
  -z|--zlib-enabled   : enable ZLIB related functions (default: true)
  -b|--brotli-enabled : enable BROTLI related functions
                      : (x86/x64 default: true, arm/arm64 default: false)
  -i|--iconv-enabled  : enable ICONV related functions (default: true)
  -c|--compiler       : compiler (default: g++)
  -p|--platform       : platform: x86 / x64 / arm / arm64
                      : (default: current machine arch platform)
  -e|--clean          : clean compilation intermediate temp files
  -r|--remove         : remove all compilation target files
  -v|--version        : print hp-socket version
  -h|--help           : print this usage message
----------------------+-------------------------------------------------
//编译生成的动态库目录
cd /HP-Socket/Linux/lib/hpsocket/arm64/**
```
##### CSerialPort库
```console
- aarch64 on ubuntu 18.04
$ sudo apt-get install g++-aarch64-linux-gnu
$ cd CSerialPort
$ mkdir bin_aarch64 && cd bin_aarch64
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=./cmake/toolchain_aarch64.cmake
$ cmake --build .
```

### 项目构建

使用**CMake**构建本项目.
当您在项目的根路径时, 可以执行以下指令:

```console
// BUILD
$ 将生成的第三方动态库文件放在 lib文件夹内
$ mkdir build
$ cd build
$ cmake .. // 默认为有日志
$ make
最后将在 bin 目录生成默认应用程序

//CMakeList.txt 59行 此处更改默认生成目录位置
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
```
### 日志模块
日志模块采用单例加锁的方式并提供四个宏定义并有四个级别的日志记录:
+ `LOG_INFO`
+ `LOG_WARNING`
+ `LOG_ERROR`
+ `LOG_FATAL`
日志模块线程安全可以获取线程ID 行数 函数名称 可以讲日志导入文件(默认关闭)
可以通过在CMake构建中传递标志`-DLOG_LEVEL=NOLOG`来禁用任何日志记录
### 网络模块(NetWorkManager)
提供公用的网络收发处理
```CPP
//内部通过监听器接口处理数据
class NetWorkManager
{
private:
	/* data */
public:
	NetWorkManager(/* args */);
	~NetWorkManager();
private:
//内部创建 监听接口
	CListenerImpl *listener;
    IUdpClient    *client;
};
//通过监听器接口处理数据
EnHandleResult CListenerImpl::OnReceive(IUdpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{  
    //这里对 pData做数据处理或者转发
    return HR_OK;
}
```
### 串口模块
提供串口处理
```CPP
暂时先实例化三个串口
class SerialListener :public CSerialPortListener
{

public:
    SerialListener();
    SerialListener(CSerialPort * port1,CSerialPort * port2,CSerialPort * port3);
    ~SerialListener();
    // 响应读取事件
    void onReadEvent(const char *portName, unsigned int readBufferLen)override;
private:
    CSerialPort * s_port1;
    CSerialPort * s_port2;
    CSerialPort * s_port3;
    /* data */
};
```
### MQTT模块 
```

```










