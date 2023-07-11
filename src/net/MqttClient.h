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

#include <iostream>
#include <map>
#include <mutex>
#include <string>
#include "CLog.h"
#include "async_client.h"
#include "topic.h"

class MqttClient {
 public:
  using mqttPtr = std::shared_ptr<mqtt::topic>;
  //
  MqttClient();
  virtual ~MqttClient();

  bool Start(
      const std::string& serverURI, const std::string& clientId,
      const mqtt::create_options& opts = mqtt::create_options(MQTTVERSION_5)) {
    _client = new mqtt::async_client(serverURI, clientId, opts);
    _client->set_connected_handler(
        std::bind(&MqttClient::OnConnected, this, std::placeholders::_1));
    _client->set_connection_lost_handler(
        std::bind(&MqttClient::OnConnectedLost, this, std::placeholders::_1));
    _client->set_message_callback(
        std::bind(&MqttClient::OnReceive, this, std::placeholders::_1));
    _client->set_disconnected_handler(std::bind(&MqttClient::OnDisconnected,
                                                this, std::placeholders::_1,
                                                std::placeholders::_2));
    _client->set_update_connection_handler(
        std::bind(&MqttClient::OnUpdateConnected, this, std::placeholders::_1));

    return true;
  }

  /**
   * @brief 链接
   *
   * @param ops 服务信息强度
   */
  void Connect(mqtt::connect_options ops) { _client->connect(ops); }
  /**
   * @brief
   * Reconnect
   */
  void reConnect() { _client->reconnect(); }
  /**
   * @brief 判断是否链接
   *
   * @return true
   * @return false
   */
  bool isConnected() { return _client->is_connected(); }
  /**
   * @brief 发布消息
   *
   * @param topic  主题
   * @param payload  内容
   * @param qos 服务信息强度 (默认2)
   * @param retained  返回令牌默认ture
   */
  void publish(mqtt::string_ref topic, std::string payload, int qos = 2,
               bool retained = true) {
    _client->publish(topic, (void*)(payload.c_str()), payload.size());
  }
  /**
   * @brief 订阅消息
   *
   * @param topicFilter  主题
   * @param qos   服务信息强度(默认2)
   */
  void subscribe(const string& topicFilter, int qos = 2) {
    _client->subscribe(topicFilter, qos);
  }
  //各种回调
  void OnConnected(const std::string& cause);

  void OnConnectedLost(const std::string& cause);

  void OnReceive(const mqtt::const_message_ptr message);

  void OnDisconnected(const mqtt::properties& proe, mqtt::ReasonCode resason);

  bool OnUpdateConnected(mqtt::connect_data& data);

 private:
  mqtt::async_client* _client;
  // No
};

using MQTTClientPtr = std::shared_ptr<MqttClient>;