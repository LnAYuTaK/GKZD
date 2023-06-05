#include <memory>
#include <iostream>
#include "NetWorkManager.h"

std::string char2hexstr(const BYTE* str, int len)
{
    static const char hexTable[17] = "0123456789ABCDEF";

    std::string result;
    for (int i = 0; i < len; ++i)
    {
        result += "0x";
        result += hexTable[(unsigned char)str[i] / 16];
        result += hexTable[(unsigned char)str[i] % 16];
        result += " ";
    }
    return result;
}
EnHandleResult CListenerImpl::OnPrepareConnect(IUdpClient* pSender, CONNID dwConnID, SOCKET socket)
{

    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult CListenerImpl::OnConnect(IUdpClient* pSender, CONNID dwConnID)
{

    std::cout << " Connect !" <<std::endl;
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult CListenerImpl::OnHandShake(IUdpClient* pSender, CONNID dwConnID)
{

    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult CListenerImpl::OnReceive(IUdpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
    std::cout << "Client Recv" <<char2hexstr(pData,iLength) << std::endl;
    pSender->Send(pData,iLength);
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult CListenerImpl::OnSend(IUdpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
    std::cout << "Client Send:" << char2hexstr(pData,iLength) << std::endl;
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult CListenerImpl::OnClose(IUdpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
    std::cout << " Close !" <<std::endl;
    return HR_OK;
}
/***********************************************************************************************/
NetWorkManager::NetWorkManager(/* args */)
    :listener(new CListenerImpl())
    ,client(nullptr)
{
    client = HP_Create_UdpClient((IUdpClientListener*)(listener));
    client->Start("192.168.0.23", 5555);
}
/***********************************************************************************************/
NetWorkManager::~NetWorkManager()
{

}
/***********************************************************************************************/
