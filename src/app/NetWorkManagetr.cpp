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
    std::cout << "Receive" <<std::endl;
    CBufferPtr buffer(100);
    EnFetchResult result = app()->newMgr()->Server()->Fetch(dwConnID, buffer, (int)buffer.Size());
    TPkgHeader* pHeader = (TPkgHeader*)buffer.Ptr();

    CLOG_INFO("(head) -> seq: %d, body_len: %d", pHeader->seq, pHeader->body_len);
    
    // TPkgInfo* pInfo			= ::FindPkgInfo(pSender, dwConnID);
    // if(pInfo != nullptr)
    // {
    //     int required = pInfo->length;
    //     int remain =   iLength;

    //     while(remain >= required)
    //     {
    //         remain -= required;
    //         CBufferPtr buffer(required);

    //         EnFetchResult result = app()->newMgr()->Server()->Fetch(dwConnID, buffer, (int)buffer.Size());
    //         if(result == FR_OK)
    //         {
    //             if(pInfo->is_header)
    //             {
    //                 TPkgHeader* pHeader = (TPkgHeader*)buffer.Ptr();
    //                 CLOG_INFO("(head) -> seq: %d, body_len: %d", pHeader->seq, pHeader->body_len);
    //                 required = pHeader->body_len;
    //             }
    //             else
    //             {
    //                 TPkgBody* pBody = (TPkgBody*)(BYTE*)buffer;
    //                 CLOG_INFO("(body) -> name: %s, age: %d, desc: %s", pBody->name, pBody->age, pBody->desc);
    //                 required = sizeof(TPkgHeader);
    //             }
    //             pInfo->is_header = !pInfo->is_header;
    //             pInfo->length	 = required;

    //             if(!pSender->Send(dwConnID, buffer, (int)buffer.Size()))
    //                 return HR_ERROR;
    //         }
    //     }
    // }
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
