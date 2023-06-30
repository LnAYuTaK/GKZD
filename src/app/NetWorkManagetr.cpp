#include <memory>
#include <iostream>
#include "NetWorkManager.h"
#include "App.h"
#include "CLOG.h"

/***********************************************************************************************/
EnHandleResult TCPServerListener ::OnPrepareListen(ITcpServer* pSender, SOCKET soListen)
{
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener ::OnAccept(ITcpServer* pSender, 
                                            CONNID dwConnID, 
                                            UINT_PTR soClient)
{
    TCHAR szAddress[100];
    int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
    USHORT usPort;
	pSender->GetRemoteAddress(dwConnID, szAddress, iAddressLen, usPort);
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener ::OnHandShake(ITcpServer* pSender, CONNID dwConnID)
{
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener ::OnReceive(ITcpServer* pSender, 
                                                CONNID dwConnID, 
                                                int iLength)
{
    Bytes buffer(iLength);
    app()->NetWorkMgr()->Server()->Fetch(dwConnID,buffer.ptr(),iLength);
    app()->BlcokerMgr()->Publish<Bytes>("TCPSever",buffer);
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener ::OnSend(ITcpServer* pSender, 
                                            CONNID dwConnID, 
                                            const BYTE* pData, 
                                            int iLength)
{
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener ::OnClose(ITcpServer* pSender, 
                                            CONNID dwConnID, 
                                            EnSocketOperation enOperation, 
                                            int iErrorCode)
{   
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener ::OnShutdown(ITcpServer* pSender)
{
 
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPClientListener::OnPrepareConnect(ITcpClient* pSender,
                                                    CONNID dwConnID, 
                                                    SOCKET socket ) 
{

    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPClientListener::OnConnect(ITcpClient* pSender, CONNID dwConnID)
{
    CLOG_INFO()<< "TCP Client Connect";
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPClientListener::OnHandShake(ITcpClient* pSender, CONNID dwConnID)
{

    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPClientListener::OnReceive(ITcpClient* pSender, 
                                            CONNID dwConnID, 
                                            int iLength)
{

    Bytes buffer(iLength);
    app()->NetWorkMgr()->Client()->Fetch(buffer.ptr(),iLength);
    app()->BlcokerMgr()->Publish<Bytes>("TCPClient",buffer);
    return HR_OK;
}

/***********************************************************************************************/
EnHandleResult TCPClientListener::OnSend(ITcpClient* pSender, 
									CONNID dwConnID, 
									const BYTE* pData, 
									int iLength)
{
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPClientListener::OnClose(ITcpClient* pSender, 
                                        CONNID dwConnID, 
                                        EnSocketOperation enOperation, 
                                        int iErrorCode)
{
    return HR_OK;
}
/***********************************************************************************************/
NetWorkManager::NetWorkManager(/* args */)
    :_tcpServer(&_slistener)
    ,_tcpClient(&_clisterner)
    ,_mqttClinet(std::string("192.168.16.231:1883"),
                 std::string("client"),
                 mqtt::create_options(MQTTVERSION_5))
{

}
/***********************************************************************************************/
NetWorkManager::~NetWorkManager()
{
    HP_Destroy_TcpPullServer(this->_tcpServer);
    HP_Destroy_TcpPullClient(this->_tcpClient);
}
/***********************************************************************************************/
