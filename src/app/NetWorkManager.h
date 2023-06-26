/**
 * @file NetWorkManager.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief  网络通信管理器 (管理所有网络服务器客户端等网络接口)
 * @version 0.1
 * @date 2023-06-26
 * @copyright Copyright (c) 2023
 */
#pragma once 

#include "HPSocket.h"
#include "SocketInterface.h"
#include  "SimpleSigleton.h"

class TCPListenerImpl :public  CTcpPullServerListener
{
public:
	virtual EnHandleResult OnPrepareListen(ITcpServer* pSender, SOCKET soListen);
	virtual EnHandleResult OnAccept(ITcpServer* pSender, CONNID dwConnID, UINT_PTR soClient);
	virtual EnHandleResult OnHandShake(ITcpServer* pSender, CONNID dwConnID);
	virtual EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength);
	virtual EnHandleResult OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength);
	virtual EnHandleResult OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode);
	virtual EnHandleResult OnShutdown(ITcpServer* pSender);
};

class NetWorkManager
{
	DISALLOW_COPY_AND_ASSIGN(NetWorkManager)
public:
	NetWorkManager(/* args */);
	virtual~NetWorkManager();
	CTcpPullServerPtr & Server() {return server;}	
    
private:
    TCPListenerImpl   listener;
	CTcpPullServerPtr server;
};


