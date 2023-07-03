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

/***********************************************************************************************/
//CallBack Function//
void MqttClient::OnConnected(const std::string& cause)
{
    CLOG_INFO() << "MqttClient OnConnected";
    this->subscribe("TOPIC");
    this->publish("TOPIC","MSGSSSSSS");
}
/***********************************************************************************************/
void MqttClient::OnConnectedLost(const std::string& cause)
{
    CLOG_WARN()<<"Reconnect";
    
}
/***********************************************************************************************/
void MqttClient::OnReceive(const mqtt::const_message_ptr message)
{
   auto msgStr = message->get_payload_str();
   auto topstr = message->get_topic();
   CLOG_INFO() << "MQTT TOPIC: " << topstr ;
   CLOG_INFO() << "MQTT PLAYLOAD: "<< msgStr;
}
/***********************************************************************************************/
void MqttClient::OnDisconnected(const mqtt::properties& proe, mqtt::ReasonCode resason)
{

}
/***********************************************************************************************/
bool MqttClient::OnUpdateConnected(mqtt::connect_data &data)
{
    return false;
}
/***********************************************************************************************/
