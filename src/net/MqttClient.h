/**
 * @file MqttClient.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 

#include "async_client.h"
#include "topic.h"  
#include <iostream>
#include <string>
#include "CLOG.h"
#include <mutex>
#include <map>

class MqttClient
{
public:

	using mqttPtr = std::shared_ptr<mqtt::topic>;
	//
	MqttClient(const std::string& serverURI, 
			   const std::string& clientId,
			   const mqtt::create_options& opts = mqtt::create_options(MQTTVERSION_5));
	virtual ~MqttClient();
    /**
     * @brief 链接
     * 
     * @param ops 服务信息强度
     */
	void Connect(mqtt::connect_options ops)
	{
		_client.connect(ops);
	}
    /**
     * @brief 判断是否链接
     * 
     * @return true 
     * @return false 
     */
    bool isConnected() 
	{ 
		return _client.is_connected();
	}
	/**
	 * @brief 发布消息
	 * 
	 * @param topic  主题
	 * @param payload  内容
	 * @param qos 服务信息强度 (默认2)
	 * @param retained  返回令牌默认ture
	 */
	void publish(mqtt::string_ref topic, 
				 std::string payload,
				 int qos = 2, bool retained = true)
	{
		_client.publish(topic,(void*)(payload.c_str()),payload.size());
	}
    /**
     * @brief 订阅消息
     * 
     * @param topicFilter  主题
     * @param qos   服务信息强度(默认2)
     */
	void subscribe(const string& topicFilter, int qos=2)
	{
		_client.subscribe(topicFilter,qos);
	}
	//各种回调
    void OnConnected(const std::string& cause);

	void OnConnectedLost(const std::string& cause);

	void OnReceive(const mqtt::const_message_ptr message);
 
	void OnDisconnected(const mqtt::properties& proe, mqtt::ReasonCode resason);

	bool OnUpdateConnected(mqtt::connect_data &data);
private: 
	mqtt::async_client _client;
	//No 
	MqttClient() =delete;
};

using MQTTClientPtr = std::shared_ptr<MqttClient>;