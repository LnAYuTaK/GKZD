#include <memory>
#include <iostream>
#include "NetWorkManager.h"
#include "App.h"
#include "CLOG.h"
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
    //Test
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
