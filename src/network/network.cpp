//
// Created by zbguo on 3/18/25.
//

#include <network.hpp>

#include "node.hpp"

namespace paxosdb {
    Network::Network(): _oNode(nullptr) {}
    Network::~Network() {

    }

    void Network::initNetworkThreads() {

    }

    void Network::stopNetworkThreads() {

    }

    void Network::onReceiveMessage(const char* message, const unsigned int message_size) {
        if (_oNode != nullptr) {
            _oNode->onReceiveMessage(message, message_size);
        }
    }



}
