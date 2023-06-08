
#pragma once 
#include "SimpleSigleton.h"
enum DecodingType
{
   UART_ENCOD,
   TCP_ENCOD,
   UDP_ENCOD,
};

class ProtocolParse
{
    DECLARE_SINGLETON(ProtocolParse)
public:
    ~ProtocolParse();
    static void ProtocolHandle(char *data ,int length,DecodingType type);
private:
    //example 

    /* data */
};

ProtocolParse * Protocol();
