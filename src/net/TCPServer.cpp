#include "TCPServer.h"

#include "Bytes.h"
#include "CLog.h"

#include "App.h"
#include "NetWorkManager.h"
#include "BlockerManager.h"

EnHandleResult TCPServerListener::OnPrepareListen(ITcpServer* pSender,
                                                  SOCKET soListen) {
  return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener::OnAccept(ITcpServer* pSender, CONNID dwConnID,
                                           UINT_PTR soClient) {
  // TCHAR szAddress[100];
  // int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
  // USHORT usPort;
  // pSender->GetRemoteAddress(dwConnID, szAddress, iAddressLen, usPort);
  return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener::OnHandShake(ITcpServer* pSender,
                                              CONNID dwConnID) {
  return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener::OnReceive(ITcpServer* pSender,
                                            CONNID dwConnID, int iLength) {
  Bytes buffer(iLength);
  app()->NetWorkMgr()->Server()->Fetch(dwConnID, buffer.ptr(), iLength);
  app()->BlcokerMgr()->Publish<Bytes>("TCPSever", buffer);
  return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener::OnSend(ITcpServer* pSender, CONNID dwConnID,
                                         const BYTE* pData, int iLength) {
  return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener::OnClose(ITcpServer* pSender, CONNID dwConnID,
                                          EnSocketOperation enOperation,
                                          int iErrorCode) {
  return HR_OK;
}
/***********************************************************************************************/
EnHandleResult TCPServerListener::OnShutdown(ITcpServer* pSender) {
  return HR_OK;
}