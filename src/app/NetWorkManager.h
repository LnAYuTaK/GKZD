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
#include "SimpleSigleton.h"
#include "MqttClient.h"
#include "CLOG.h"

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

class TCPClientListener :public  CTcpPullClientListener
{
public:
	virtual EnHandleResult OnPrepareConnect(ITcpClient* pSender, 
											CONNID dwConnID, 
											SOCKET socket)override;

	virtual EnHandleResult OnConnect(ITcpClient* pSender, CONNID dwConnID)override;

	virtual EnHandleResult OnHandShake(ITcpClient* pSender, CONNID dwConnID)override;

	virtual EnHandleResult OnReceive(ITcpClient* pSender, 
										CONNID dwConnID, 
										int iLength)override;

	virtual EnHandleResult OnSend(ITcpClient* pSender, 
									CONNID dwConnID, 
									const BYTE* pData, 
									int iLength)override;

	virtual EnHandleResult OnClose(ITcpClient* pSender, 
										CONNID dwConnID, 
										EnSocketOperation enOperation, 
										int iErrorCode)override;
};

class NetWorkManager
{
	DISALLOW_COPY_AND_ASSIGN(NetWorkManager)
public:
	NetWorkManager(/* args */);
	virtual~NetWorkManager();
	CTcpPullServerPtr & Server()     {return _tcpServer;}
	CTcpPullClientPtr & Client()     {return _tcpClient;}	
	MqttClient        & Mqtt()       {return _mqttClinet;} 
private:
    MqttClient          _mqttClinet;
//CLient
	TCPClientListener   _clisterner;
	CTcpPullClientPtr   _tcpClient;
//Server
    TCPServerListener   _slistener;
	CTcpPullServerPtr   _tcpServer;
	
};


