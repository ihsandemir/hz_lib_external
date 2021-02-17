#include <iostream>

#include <hazelcast/client/hazelcast_client.h>

int main() {
    auto hz = hazelcast::new_client().get();

    auto topic = hz.get_topic("mytopic").get();

    topic->add_message_listener(
            hazelcast::client::topic::listener().on_received([](hazelcast::client::topic::message &&m) {
                std::cout << "C++ client received message for topic. Message:"
                          << m.get_message_object().get<std::string>().value() << "\n";
            })).get();

    std::cout << "Added listener\n";
    int counter = 0;
    while (true) {
        topic->publish((boost::format("Message from C++ client %1%") % (counter++)).str());
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
