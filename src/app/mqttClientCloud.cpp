#include <iostream>
#include <string>

#include "mqttClientCloud.h"

using namespace std;

namespace cloud {
    // mqtt_client类构造函数实现
    mqtt_client::mqtt_client()
        // 1.The server URI string  2.The client ID string that we provided to the server   3.The MQTT protocol version we're connected at
        : cli_(BROKER_HOST, "client", mqtt::create_options(MQTTVERSION_5))
        // 1.The client to which this topic is connected	2.The topic name(pub & sub)   3.The default QoS
        , topic_(cli_,"haojuhu", 1)  
    {
        //! Handler on connection lost, do reconnect here
        cli_.set_connection_lost_handler([this](const string& info) {
            std::cout<<"mqtt connection lost <" << info << ">, reconnting"<<std::endl;
            cli_.reconnect();
        });

        //! Handler on connected, it'll subscribe the topic and publish online info
        cli_.set_connected_handler([this](const string& info) {
            std::cout << "mqtt connected <" << info << ">"<<std::endl;
            topic_.subscribe(mqtt::subscribe_options(true));   // client订阅topic[haojuhu]
            topic_.publish("online");                          // client发布消息"online"至topic[haojuhu]
        });
    }
    //2.mqtt_client类析构函数实现
    mqtt_client::~mqtt_client()
    {
        cli_.disconnect();
        cli_.disable_callbacks();
    }

    /**
     * @brief       Publish message to topic，发布消息给topic
     * @param[in]   message The message payload
     */
    void mqtt_client::send(const string& message) 
    { 
        topic_.publish(message); 
    }

    /**
     * @brief       Set mqtt message handler，设置mqtt消息处理句柄（也就是函数对象cb）
     * @note        The mqtt connection will established here
     * @param[in]   cb  The message handler
     */
    void mqtt_client::set_message_handler(message_handler cb)
    {
        //! Set message callback here
        cli_.set_message_callback([cb](mqtt::const_message_ptr message) 
        {
            cb(message->get_payload_str());   //执行函数cb
        });

        //! Set connect options and do connect
        auto opts = mqtt::connect_options_builder()
                        .mqtt_version(MQTTVERSION_5)
                        .clean_start(true)
                        .finalize();
        cli_.connect(opts);
    }
}  // namespace cloud
