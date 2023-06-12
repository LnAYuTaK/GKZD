#include "DriverManager.h"
#include <iostream>
#include "CLOG.h"
DriverManager::DriverManager(/* args */)
{
   serial1 =  new Serial1();
   serial2 =  new Serial2();

   auto s1 = dynamic_cast<Serial1 *>(serial1);
   s1->init("/dev/ttyS5");
   if(s1->open())
   {
      CLOG_INFO("%s","ttyS5 open");
   }
   auto s2 = dynamic_cast<Serial2 *>(serial2);
   s2->init("/dev/ttyS4");
   if(s2->open())
   {
       CLOG_INFO("%s","ttyS4 open");
   }
   this->addDriver(serial1);
   this->addDriver(serial2);
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




