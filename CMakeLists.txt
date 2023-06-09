cmake_minimum_required(VERSION 2.8)

#项目名称
project(demo)

MESSAGE(STATUS "PROJECT")

#设置交叉编译器
# 交叉编译的系统名称
set(CMAKE_SYSTEM_NAME Linux)
# 交叉编译的CPU架构
set(CMAKE_SYSTEM_PROCESSOR aarch64)

#指明C和C++编译器
set(CMAKE_C_COMPILER aarch64-linux-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-g++)


MESSAGE(STATUS "CMAKE_C_COMPILER:" ${CMAKE_C_COMPILER})
MESSAGE(STATUS "CMAKE_CXX_COMPILER:" ${CMAKE_CXX_COMPILER})
#对FIND_PROGRAM()起作用，有三种取值，NEVER,ONLY,BOTH,第一个表示不在你CMAKE_FIND_ROOT_PATH下进行查找，第二个表示只在这个路径下查找，第三个表示先查找这个路径，再查找全局路径，对于这个变量来说，一般都是调用宿主机的程序，所以一般都设置成NEVER
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#下面的三个选项表示只在交叉环境中查找库和头文件
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

#添加头文件的路径 
include_directories(src/common)
include_directories(src/log)
include_directories(src/driver)
include_directories(src/app)
#第三方库
include_directories(src/thirdparty/CSerialPort)
include_directories(src/thirdparty/HP-Socket)
include_directories(src/thirdparty/MQTT)
#输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#添加动态连接库的路径
link_directories(${CMAKE_SOURCE_DIR}/lib) 

#添加编译选项
add_definitions(-Wall -O2 -g -Wpsabi -fno-aggressive-loop-optimizations)
add_definitions(-shared)
add_definitions(-nostartfiles)
add_definitions(-std=c++17)

#添加源文件路径
aux_source_directory(${CMAKE_SOURCE_DIR}/src/app SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/driver SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/common SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/log SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/. SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/thirdparty/CSerialPort SRC_LIST)

#add_executable(想要生成的程序名 源文件)
add_executable(demo  ${SRC_LIST})

#添加编译时的依赖库
target_link_libraries(${PROJECT_NAME}  -lpthread -lrt -ldl -lm )
target_link_libraries(${PROJECT_NAME}  libcserialport.so)
target_link_libraries(${PROJECT_NAME}  libhpsocket.so )
target_link_libraries(${PROJECT_NAME}  libpaho-mqtt3a.so)
target_link_libraries(${PROJECT_NAME}  libpaho-mqttpp3.so)

