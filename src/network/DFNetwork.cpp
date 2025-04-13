//
// Created by zbguo on 3/18/25.
//

#include "DFNetwork.hpp"

#include <iostream>
#include <ostream>

namespace paxosdb {
    DFNetwork::DFNetwork(): _udpRecvMessage(this){

    }

    // DFNetwork.cpp
    DFNetwork::~DFNetwork() {
        std::cout << "[DEBUG] DFNetwork destructor called\n";
        _udpRecvMessage.stop();
        _udpSendMessage.stop();
    }


    int DFNetwork::init(const std::string &ip, const int port, const int numIOThreads) {
        std::cout << "DFNetwork::init(" << ip << ", " << port << ")" << std::endl;
        int udpSendInit = _udpSendMessage.init();
        if (udpSendInit < 0) {
            return udpSendInit;
        }
        int udpRecvInit = _udpRecvMessage.init(port);
        if (udpRecvInit < 0) {
            return udpRecvInit;
        }

        return 0;
    }

    void DFNetwork::run() {
        // implicitly call run() function implementation for each udp variable
        std::cout << "DFNetwork::run()" << std::endl;
        _udpRecvMessage.start();
        _udpSendMessage.start();
    }

    int DFNetwork::sendMessage(const std::string &ip, const int port, const std::string &message) {
        return _udpSendMessage.AddMessage(ip, port, message);
    }




}
