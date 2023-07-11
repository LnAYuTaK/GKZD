

#include "NetWorkManager.h"
/***********************************************************************************************/
NetWorkManager::NetWorkManager(/* args */)
    : _tcpServer(&_slistener),
      _tcpClient(&_clisterner),
      _mqttClient(make_shared<MqttClient>()) {}
/***********************************************************************************************/
NetWorkManager::~NetWorkManager() {
  HP_Destroy_TcpPullServer(this->_tcpServer);
  HP_Destroy_TcpPullClient(this->_tcpClient);
}
/***********************************************************************************************/
