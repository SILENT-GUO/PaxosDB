//
// Created by zbguo on 3/18/25.
//

#ifndef DFNETWORK_HPP
#define DFNETWORK_HPP

#pragma once

#include <network.hpp>
#include <string>

#include "udp.hpp"

namespace paxosdb {
class DFNetwork final: public Network{
public:
    DFNetwork();
    virtual ~DFNetwork();

    int init(const std::string & ip, const int port, const int numIOThreads);
    void run() override;
    void stop();
    int sendMessage(const std::string &ip, const int port, const std::string & message);
private:
    UDPRecvMessage _udpRecvMessage;
    UDPSendMessage _udpSendMessage;

};
}



#endif //DFNETWORK_HPP
