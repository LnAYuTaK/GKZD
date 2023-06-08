#ifndef __MQTT_CLIENT_TO_CLOUD_HPP__
#define __MQTT_CLIENT_TO_CLOUD_HPP__

#include "mqtt/async_client.h"  // mqtt库头文件
#include "mqtt/topic.h"         // mqtt库头文件

namespace cloud {
    //! Handler on cloud message
    using message_handler = std::function<void(const std::string&)>;

    class mqtt_client
    {
    public:
        mqtt_client();
        ~mqtt_client();

        void send(const std::string& message);
        void set_message_handler(message_handler cb);

    private:
        // static constexpr const char* BROKER_HOST = "localhost:1883";        //本地测试：mosquitto
        static constexpr const char* BROKER_HOST = "broker.emqx.io:1883";       //公共mqtt broker：MQTTX
        // static constexpr const char* BROKER_HOST = "124.XXX.XXX.XXX:1883";   //云端测试：mosquitto

    private:
        mqtt::async_client cli_;
        mqtt::topic        topic_;
    };
}  // namespace cloud

#endif
