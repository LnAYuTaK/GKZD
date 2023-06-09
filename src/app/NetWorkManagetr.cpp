#include <memory>
#include <iostream>
#include "NetWorkManager.h"
#include "App.h"
#include "CLOG.h"
#include "ProtocolHelper.h"
EnHandleResult TCPListenerImpl::OnPrepareListen(ITcpServer* pSender, SOCKET soListen)
{
    std::cout << " Listen !" <<std::endl;
    return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPListenerImpl::OnAccept(ITcpServer* pSender, CONNID dwConnID, UINT_PTR soClient)
{
    TCHAR szAddress[100];
    int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
    USHORT usPort;
	pSender->GetRemoteAddress(dwConnID, szAddress, iAddressLen, usPort);
    std::cout << "ConnectID:" <<dwConnID <<  "Address:" << szAddress << "Port:" << usPort << std::endl;
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
    CBufferPtr buffer(sizeof(TPkgHeader));
    EnFetchResult result = pServer->Fetch(dwConnID, buffer, (int)buffer.Size());
    TPkgHeader *header  =  (TPkgHeader*)(buffer.Ptr());
    CLOG_INFO("(head) -> seq: %u, body_len: %d", header->seq, header->body_len);
    header->seq ++ ;
    header->body_len ++ ;
    pServer->Send(dwConnID,buffer,sizeof(TPkgHeader));
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
    CLOG_INFO("%s", "TCP Server ShutDown");
    return HR_OK;
}
/***********************************************************************************************/
NetWorkManager::NetWorkManager(/* args */)
    :listener()
    ,server(&listener)
{
  	if(!server->Start("192.168.0.232", 5351))
    {
        CLOG_INFO("%s", "TCP Server Start");
    }
 
}
/***********************************************************************************************/
NetWorkManager::~NetWorkManager()
{

}
/***********************************************************************************************/
