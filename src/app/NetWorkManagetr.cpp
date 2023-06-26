#include <memory>
#include <iostream>
#include "NetWorkManager.h"
#include "App.h"
#include "CLOG.h"
#include "BufferPtr.h"
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
    //Test
#ifdef NETWORK_TEST
    app()->BlcokerMgr()->Publish<CBufferPtr>("Data1",buffer);
#endif
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
    CLOG_INFO("%lu: Client Close",dwConnID);
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnShutdown(ITcpServer* pSender)
{
    CLOG_INFO("%s","Server ShutDown");
    return HR_OK;
}
/***********************************************************************************************/
NetWorkManager::NetWorkManager(/* args */)
    :listener()
    ,server(&listener)
{
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
