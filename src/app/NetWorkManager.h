#pragma once 
#include "HPSocket.h"
#include "SocketInterface.h"
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

enum NetWorkType{ 
	 UDP,
	 TCP,
	 MQTT
};

class NetWorkManager
{
private:
	/* data */
public:
	NetWorkManager(/* args */);
	~NetWorkManager();
	ITcpPullServer  *Server() {return this->server.Get();}	
private:
    TCPListenerImpl  listener;
	CTcpPullServerPtr server;
};


