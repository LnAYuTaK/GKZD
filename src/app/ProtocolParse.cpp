
#include "ProtocolParse.h"
#include "App.h"
#include <iostream>


//Test
void Test(char *data ,int length)
{  
    std::cout << data << std::endl;   
}


ProtocolParse * Protocol()
{
    return ProtocolParse::Instance();
}
ProtocolParse::ProtocolParse(/* args */)
{
   
}
/***********************************************************************************************/
ProtocolParse::~ProtocolParse()
{

}
/***********************************************************************************************/
void ProtocolHandle(char *data ,int length,DecodingType type)
{
    switch (type)
    {
    case TCP_ENCOD:
        //Test
        app()->threadPool()->submit(dealuart,data,length);
        /* code */
        break;
    default:
        break;
    }
}
/***********************************************************************************************/
