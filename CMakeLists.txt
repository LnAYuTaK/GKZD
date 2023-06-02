cmake_minimum_required(VERSION 2.8)

#项目名称
project(demo)

MESSAGE(STATUS "PROJECT")

#设置交叉编译器
option(ARM_CROSS_COMPILE "Arm cross compiling option" ON)
if(ARM_CROSS_COMPILE)
    MESSAGE(STATUS "Arm cross compiling...")
    # 设置目标系统
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)
    # 设置工具链目录
    set(TOOL_CHAIN_DIR /opt/hisi-linux/x86-arm/arm-himix100-linux)
    set(TOOL_CHAIN_INCLUDE 
        ${TOOL_CHAIN_DIR}/include
    )
    set(TOOL_CHAIN_LIB 
        ${TOOL_CHAIN_DIR}/lib
    )
    # 设置编译器
    set(CMAKE_C_COMPILER "arm-himix100-linux-gcc")
    set(CMAKE_CXX_COMPILER "arm-himix100-linux-g++")

    MESSAGE(STATUS "CMAKE_C_COMPILER:" ${CMAKE_C_COMPILER})
    MESSAGE(STATUS "CMAKE_CXX_COMPILER:" ${CMAKE_CXX_COMPILER})
    # 设置Cmake查找主路径
    set(CMAKE_FIND_ROOT_PATH ${TOOL_CHAIN_DIR})

    set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
    # 只在指定目录下查找库文件
    set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
    # 只在指定目录下查找头文件
    set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
    # 只在指定目录下查找依赖包
    set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

    include_directories(
        ${TOOL_CHAIN_DIR}/include
        )
    set(CMAKE_INCLUDE_PATH 
        ${TOOL_CHAIN_INCLUDE}
        )
    set(CMAKE_LIBRARY_PATH 
        ${TOOL_CHAIN_LIB}
        )
endif(ARM_CROSS_COMPILE)

#添加头文件的路径 
include_directories(src/common)
include_directories(src/log)
include_directories(src/driver)
include_directories(src/app)
#第三方库
include_directories(src/thirdparty/CSerialPort)

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
target_link_libraries(${PROJECT_NAME}  libcserialport.a)
