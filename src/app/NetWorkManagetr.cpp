#include <memory>
#include <iostream>
#include "NetWorkManager.h"
#include "App.h"
#include "CLOG.h"

/***********************************************************************************************/
NetWorkManager::NetWorkManager(/* args */)
    :_tcpServer(&_slistener)
    ,_tcpClient(&_clisterner)
    ,_mqttClient(make_shared<MqttClient>(MQTT_ADDRESS,
                 std::string(MQTT_CLIENT_NAME)))

{



}
/***********************************************************************************************/
NetWorkManager::~NetWorkManager()
{
    HP_Destroy_TcpPullServer(this->_tcpServer);
    HP_Destroy_TcpPullClient(this->_tcpClient);

}
/***********************************************************************************************/
