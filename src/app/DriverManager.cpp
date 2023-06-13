#include "DriverManager.h"
#include <iostream>
#include "CLOG.h"
DriverManager::DriverManager(/* args */)
{
   _serial1 =  new Serial1();
   _serial2 =  new Serial2();

   _serial1->init("/dev/ttyS5");
   if(_serial1->open())
   {
      CLOG_INFO("%s","ttyS5 open");
   }
   _serial2->init("/dev/ttyS4");
   if(_serial2->open())
   {
       CLOG_INFO("%s","ttyS4 open");
   }
}
/***********************************************************************************************/
DriverManager::~DriverManager()
{
   //Delete All _driverList 
    for(auto i :_driverList)
    {
        if(i!= nullptr)
        {
            delete i;
        }
    }
}
/***********************************************************************************************/
void DriverManager::addDriver(DriverBase *base)
{
    std::lock_guard<std::mutex> guard(_mt);
   _driverList.push_back(base);
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




