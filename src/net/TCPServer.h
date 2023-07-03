/**
 * @file TCPServer.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief TCP服务器
 * @version 0.1
 * @date 2023-07-03
 * 
 * 
 */
#pragma once 

#include "HPSocket.h"
#include "SocketInterface.h"

class TCPServerListener :public  CTcpPullServerListener
{
public:
	virtual EnHandleResult OnPrepareListen(ITcpServer* pSender, SOCKET soListen)override;

	virtual EnHandleResult OnAccept(ITcpServer* pSender, 
									CONNID dwConnID, 
									UINT_PTR soClient)override;

	virtual EnHandleResult OnHandShake(ITcpServer* pSender, CONNID dwConnID)override;

	virtual EnHandleResult OnReceive(ITcpServer* pSender, 
										CONNID dwConnID, 
										int iLength)override;

	virtual EnHandleResult OnSend(ITcpServer* pSender, 
									CONNID dwConnID, 
									const BYTE* pData, 
									int iLength)override;

	virtual EnHandleResult OnClose(ITcpServer* pSender, 
									CONNID dwConnID, 
									EnSocketOperation enOperation, 
									int iErrorCode)override;

	virtual EnHandleResult OnShutdown(ITcpServer* pSender)override;
};

