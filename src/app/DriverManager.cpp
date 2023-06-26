#include "DriverManager.h"
#include <iostream>
#include "CLOG.h"
DriverManager::DriverManager(/* args */)
    :_serial1(std::make_shared<Serial1>())
    ,_serial2(std::make_shared<Serial2>())
{
}
/***********************************************************************************************/
DriverManager::~DriverManager()
{
}
/***********************************************************************************************/
//Serial1 Handle 
void Serial1::onReadEvent(const char* portName, unsigned int readBufferLen)
{
        if (readBufferLen > 0)
        {
            char *data = new char[readBufferLen + 1]; // '\0'
            if (data)
            {
                // read
                int recLen = readData(data, readBufferLen);

                if (recLen > 0)
                {
                    data[recLen] = '\0';
                    std::cout << portName  << ", Length: " << recLen << ", Str: " << data << std::endl;
                    // return receive data
                    writeData(data, recLen);
                }
                delete[] data;
                data = NULL;
            }
        }
}
/***********************************************************************************************/
//Serial2 Handle 
void Serial2::onReadEvent(const char* portName, unsigned int readBufferLen)
{
        if (readBufferLen > 0)
        {
            char *data = new char[readBufferLen + 1]; // '\0'

            if (data)
            {
                // read
                int recLen = readData(data, readBufferLen);
                if (recLen > 0)
                {
                    data[recLen] = '\0';
                    std::cout << portName  << ", Length: " << recLen << ", Str: " << data << std::endl;
                    // return receive data
                    writeData(data, recLen);
                }
                delete[] data;
                data = NULL;
            }
        }
}
/***********************************************************************************************/




