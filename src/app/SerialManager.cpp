
// #include <iostream>
// #include "SerialManager.h"
// #include "BufferPtr.h"
// #include "CLOG.h"
// SerialListener::SerialListener()
// { 
//     s_port1 = new CSerialPort();
//     s_port1->init("/dev/ttyS5", // portname
//                 BaudRate9600,   // baudrate
//                 ParityNone,     // parity
//                 DataBits8,      // data bit
//                 StopOne,        // stop bit
//                 FlowNone,       // flow
//                 4096);
//     s_port1->connectReadEvent(this);
//     s_port1->open();
//     if(s_port1->isOpen())
//     {
//         CLOG_INFO("%s","/dev/ttyS5 open");
//     }
// }
// /***********************************************************************************************/
// SerialListener::~SerialListener()
// {

// }
// /***********************************************************************************************/
// //Handle UartData
// void SerialListener::onReadEvent(const char *portName, unsigned int readBufferLen)
// {
//     if (readBufferLen > 0)
//     {
//         CBufferPtr buffer(readBufferLen);
//         // read
//         int recLen = s_port1->readData(buffer, readBufferLen);
//         if (recLen > 0)
//         {
//             std::cout << std::string((char *)buffer.Ptr()) << std::endl;
//             s_port1->writeData(buffer,buffer.Size());
//         }
//     }
// }
// /***********************************************************************************************/
// SerialManager::SerialManager(/* args */)
//     :serialListener(new SerialListener())
// {
    
// }
// /***********************************************************************************************/
// SerialManager::~SerialManager()
// {
//   delete serialListener;
//   serialListener = nullptr;
// }
// /***********************************************************************************************/
