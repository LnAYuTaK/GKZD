cmake_minimum_required(VERSION 2.8)
#项目名称
project(demo)
MESSAGE(STATUS "GKZD")
#设置交叉编译器

# 交叉编译的系统名称
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
include_directories(src/log)
include_directories(src/driver)
include_directories(src/app)
#第三方库Header
include_directories(src/thirdparty/CSerialPort)
include_directories(src/thirdparty/HP-Socket)
include_directories(src/thirdparty/MQTT)
include_directories(src/thirdparty/Json)
#输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

#添加动态连接库的路径
link_directories(${CMAKE_SOURCE_DIR}/lib) 

#添加编译选项
add_definitions(-O2 -g -Wpsabi -fno-aggressive-loop-optimizations)
add_definitions(-shared)
add_definitions(-nostartfiles)
add_definitions(-std=c++17)

#添加源文件路径
aux_source_directory(${CMAKE_SOURCE_DIR}/src/app SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/driver SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/common SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/log SRC_LIST)
aux_source_directory(${CMAKE_SOURCE_DIR}/src/. SRC_LIST)

#add_executable(想要生成的程序名 源文件)
add_executable(${PROJECT_NAME}  ${SRC_LIST})


#添加编译时的依赖库
target_link_libraries(${PROJECT_NAME}  -lpthread -lrt -ldl -lm )
if(BUILD_USE_STATIC)
    # 使用第三方动态库编译项目
    message(STATUS "Use  Static ThirdLib")
    target_link_libraries(${PROJECT_NAME}  libcserialport.a)
    target_link_libraries(${PROJECT_NAME}  libhpsocket.a)
    target_link_libraries(${PROJECT_NAME}  libjsoncpp.a)
    target_link_libraries(${PROJECT_NAME}  libpaho-mqtt3a.a)
    target_link_libraries(${PROJECT_NAME}  libpaho-mqtt3c.a)
    target_link_libraries(${PROJECT_NAME}  libpaho-mqttpp3.a)
else()
    #使用第三方静态库编译项目
    message(STATUS "Use  Shard ThirdLib")
    target_link_libraries(${PROJECT_NAME}  libcserialport.so)
    target_link_libraries(${PROJECT_NAME}  libhpsocket.so )
    target_link_libraries(${PROJECT_NAME}  libpaho-mqtt3a.so)
    target_link_libraries(${PROJECT_NAME}  libpaho-mqttpp3.so)
endif()



