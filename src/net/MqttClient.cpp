#include "MqttClient.h"
MqttClient::MqttClient()
{

}
/***********************************************************************************************/
MqttClient::~MqttClient()
{
    _client->disconnect();
    _client->disable_callbacks();
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
