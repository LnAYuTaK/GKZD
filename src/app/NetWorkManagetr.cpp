#include <memory>
#include <iostream>
#include "NetWorkManager.h"
#include "App.h"
#include "CLOG.h"
#include "BufferPtr.h"

#define PORT 5351
#define IP   "192.168.16.115"

EnHandleResult TCPListenerImpl::OnPrepareListen(ITcpServer* pSender, SOCKET soListen)
{
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnAccept(ITcpServer* pSender, CONNID dwConnID, UINT_PTR soClient)
{
    TCHAR szAddress[100];
    int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
    USHORT usPort;
	pSender->GetRemoteAddress(dwConnID, szAddress, iAddressLen, usPort);
    CLOG_INFO("IP:%s--Port:%u",szAddress,usPort);
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnHandShake(ITcpServer* pSender, CONNID dwConnID)
{
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength)
{
    ITcpPullServer* pServer	= ITcpPullServer::FromS(pSender);
    CBufferPtr buffer(iLength);
    EnFetchResult result = pServer->Fetch(dwConnID, buffer, iLength);
    CLOG_INFO("%s",buffer.Ptr());
    pServer->Send(dwConnID,buffer,iLength);
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{   
    CLOG_INFO("%lu: Close",dwConnID);
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnShutdown(ITcpServer* pSender)
{
    return HR_OK;
}
/***********************************************************************************************/
NetWorkManager::NetWorkManager(/* args */)
    :listener()
    ,server(&listener)
{
  	if(server->Start(IP,PORT))
    {
        CLOG_INFO("%s--%s--%d ","TCP Server Start",IP,PORT);
    }
    else
    {
        CLOG_ERROR("%s","TCP Server Start Error");
    }
}
/***********************************************************************************************/
NetWorkManager::~NetWorkManager()
{
    if(server!= nullptr)
    {
        HP_Destroy_TcpPullServer(this->server);
    }
}
/***********************************************************************************************/
