#include "TCPClient.h"
#include "CLOG.h"
#include "Bytes.h"
#include "App.h"

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