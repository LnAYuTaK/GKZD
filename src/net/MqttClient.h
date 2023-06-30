#pragma once 

#include "async_client.h"
#include "topic.h"  
#include <iostream>
#include <string>
#include "CLOG.h"
class MqttClient
{
public:
	//
	MqttClient(const std::string& serverURI, 
			   const std::string& clientId,
			   const mqtt::create_options& opts);
	virtual ~MqttClient();

	void Connect(mqtt::connect_options &opts)
	{
	 	_client.connect(opts);
	}

//CallBack Function//
    void OnConnected(const std::string& cause)
	{
		CLOG_INFO() << "MqttClient OnConnected";
	}
	void OnConnectedLost(const std::string& cause)
	{
		CLOG_WARN()<<"Reconnect";
		_client.reconnect();
	}

	void OnReceive(const mqtt::const_message_ptr message)
	{
		
	}
 
	void OnDisconnected(const mqtt::properties& proe, mqtt::ReasonCode resason)
	{

	}

	bool OnUpdateConnected(mqtt::connect_data &data)
	{
		return false;
	}
private:   
	mqtt::async_client _client;
	//No 
	MqttClient() =delete;
};

