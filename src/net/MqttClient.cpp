#include "MqttClient.h"
MqttClient::MqttClient(const std::string& serverURI, 
			           const std::string& clientId,
			           const mqtt::create_options& opts)
    :_client(serverURI,clientId, opts) 
{
    _client.set_connected_handler(std::bind(&MqttClient::OnConnected,
                                        this, 
                                        std::placeholders::_1));
    _client.set_connection_lost_handler(std::bind(&MqttClient::OnConnectedLost,
                                        this, 
                                        std::placeholders::_1));
    _client.set_message_callback(std::bind(&MqttClient::OnReceive, 
                                        this, 
                                        std::placeholders::_1));
    _client.set_disconnected_handler(std::bind(&MqttClient::OnDisconnected,
                                        this,
                                        std::placeholders::_1,
                                        std::placeholders::_2));
    _client.set_update_connection_handler(std::bind(&MqttClient::OnUpdateConnected,
                                        this,
                                        std::placeholders::_1));
}
/***********************************************************************************************/
MqttClient::~MqttClient()
{
    _client.disconnect();
    _client.disable_callbacks();
}

