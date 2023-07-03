/**
 * @file MqttClient.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief MQTT客户端 
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
	MqttClient(const std::string& serverURI, 
			   const std::string& clientId,
			   const mqtt::create_options& opts = mqtt::create_options(MQTTVERSION_5));
	virtual ~MqttClient();
    /**
     * @brief 连接MQTT服务器
     * 注意是异步连接
     * @param ops 服务消息质量
     */
	void Connect(mqtt::connect_options ops)
	{
		_client.connect(ops);
	}
    /**
     * @brief 客户端是否连接
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
	 * @param topic 主题
	 * @param payload  消息载体默认
	 * @param qos 服务消息质量(默认2)
	 * @param retained  返回令牌默认false
	 */
	void publish(mqtt::string_ref topic, 
				 std::string str,
				 int qos = 2, bool retained = true)
	{
		_client.publish(topic,(void*)(str.c_str()),str.size());
	}
    /**
     * @brief 订阅消息
     * 
     * @param topicFilter 主题 
     * @param qos 服务消息质量(默认2)  
     */
	void subscribe(const string& topicFilter, int qos=2)
	{
		_client.subscribe(topicFilter,qos);
	}
    /**
     * @brief 成功连接回调
     * 
     * @param cause 
     */
    void OnConnected(const std::string& cause);
    /**
     * @brief 连接失败回调
     * 
     * @param cause 
     */
	void OnConnectedLost(const std::string& cause);
	/**
	 * @brief 接收数据回调
	 * 
	 * @param message 
	 */
	void OnReceive(const mqtt::const_message_ptr message);
 	/**
	 * @brief 断开连接回调
	 * 
	 * @param message 
	 */
	void OnDisconnected(const mqtt::properties& proe, mqtt::ReasonCode resason);
 	/**
	 * @brief 更新连接数据的回调
	 * 
	 * @param message 
	 */
	bool OnUpdateConnected(mqtt::connect_data &data);
private: 
	mqtt::async_client _client;
	//No 
	MqttClient() =delete;
};

using MQTTClientPtr = std::shared_ptr<MqttClient>;