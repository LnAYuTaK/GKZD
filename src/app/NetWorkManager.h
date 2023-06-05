#pragma once 
#include "HPSocket.h"
#include "SocketInterface.h"
class CListenerImpl : public CUdpClientListener
{
public:
	virtual EnHandleResult OnPrepareConnect(IUdpClient* pSender, CONNID dwConnID, SOCKET socket)override;

	virtual EnHandleResult OnConnect(IUdpClient* pSender, CONNID dwConnID) override;

	virtual EnHandleResult OnHandShake(IUdpClient* pSender, CONNID dwConnID) override;

	virtual EnHandleResult OnReceive(IUdpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)override;

	virtual EnHandleResult OnSend(IUdpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength)override ;

	virtual EnHandleResult OnClose(IUdpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)override;
};

class NetWorkManager
{
private:
	/* data */
public:
	NetWorkManager(/* args */);
	~NetWorkManager();
private:
	CListenerImpl *listener;
    //IUdpClient* HP_Create_UdpClient(IUdpClientListener* pListener);
    IUdpClient    *client;
};


