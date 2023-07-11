cmake_minimum_required(VERSION 3.2)
#项目名称
project(ZD903Q)
MESSAGE(STATUS "ZD903Q")
#设置交叉编译器
#交叉编译的系统名称
set(CMAKE_SYSTEM_NAME Linux)
# 交叉编译的CPU架构
set(CMAKE_SYSTEM_PROCESSOR aarch64)
#指明C和C++编译器
set(CMAKE_C_COMPILER aarch64-linux-gcc)
set(CMAKE_CXX_COMPILER aarch64-linux-g++)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

message(STATUS "CMAKE_C_COMPILER:" ${CMAKE_C_COMPILER})
message(STATUS "CMAKE_CXX_COMPILER:" ${CMAKE_CXX_COMPILER})

#设置使用是否使用动态库
set(BUILD_USE_STATIC   ON CACHE BOOL "Build Use static library")

#添加头文件的路径 
include_directories(src/common)
include_directories(src/device)
include_directories(src/app)
include_directories(src/db)
include_directories(src/net)
include_directories(src/config)
#第三方库Header
include_directories(thirdparty/include/CSerialPort)
include_directories(thirdparty/include/HP-Socket)
include_directories(thirdparty/include/MQTT)
include_directories(thirdparty/include//MQTT/mqtt)
include_directories(thirdparty/include/Protobuf)
include_directories(thirdparty/include/Sqlite3)
#输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#添加编译选项
add_definitions(-O2 -g -Wpsabi -fno-aggressive-loop-optimizations)
add_definitions(-nostartfiles)
add_definitions(-std=c++17)

#添加源文件路径
aux_source_directory(${CMAKE_SOURCE_DIR}/src/app SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/device SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/common SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/db SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/net SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/config SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/. SRC_LIST)

#添加动态连接库的路径
link_directories(${CMAKE_SOURCE_DIR}/thirdparty/lib) 

#add_executable(想要生成的程序名 源文件)
add_executable(${PROJECT_NAME}  ${SRC_LIST})

if(BUILD_USE_STATIC)
    # 使用第三方动态库编译项目
    message(STATUS "Use  Static ThirdLib")
    target_link_libraries(${PROJECT_NAME}  
                            libcserialport.a
                            libhpsocket.a
                            libpaho-mqttpp3.a
                            libpaho-mqtt3a.a  
                            libsqlite3.so
                            libprotobuf.so
                            libprotoc.so)
else()
    #使用第三方静态库编译项目
    message(STATUS "Use  Shard ThirdLib")
    target_link_libraries(${PROJECT_NAME}   
                            libcserialport.so
                            libhpsocket.so 
                            libsqlite3.so
                            libpaho-mqtt3a.so
                            libpaho-mqttpp3.so
                            libprotobuf.so
                            libprotoc.so)
    endif()

target_link_libraries(${PROJECT_NAME}  -lpthread -lrt -ldl -lm)

