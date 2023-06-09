#include <iostream>
#include <string>

#include "mqttClientCloud.h"

using namespace std;
mqtt_client::mqtt_client()
    :cli_(BROKER_HOST, "client", mqtt::create_options(MQTTVERSION_5))
    ,topic_(cli_,"haojuhu", 1)  
{
    cli_.set_connection_lost_handler([this](const string& info) {
        std::cout<<"mqtt connection lost <" << info << ">, reconnting"<<std::endl;
        cli_.reconnect();
    });
    cli_.set_connected_handler([this](const string& info) {
        std::cout << "mqtt connected <" << info << ">"<<std::endl;
        topic_.subscribe(mqtt::subscribe_options(true));
        topic_.publish("online");                          
    });
}
/***********************************************************************************************/
mqtt_client::~mqtt_client()
{
    cli_.disconnect();
    cli_.disable_callbacks();
}
/***********************************************************************************************/
void mqtt_client::send(const string& message) 
{ 
    topic_.publish(message); 
}
/***********************************************************************************************/
void mqtt_client::set_message_handler(message_handler cb)
{
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
/***********************************************************************************************/
