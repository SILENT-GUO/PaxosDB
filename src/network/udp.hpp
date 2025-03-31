//
// Created by zbguo on 3/19/25.
//

#ifndef UDP_HPP
#define UDP_HPP

#pragma once
#include "concurrent.hpp"

namespace paxosdb {

class DFNetwork;

class UDPRecvMessage: public Thread {
public:
    explicit UDPRecvMessage(DFNetwork * network);
    ~UDPRecvMessage() override;

    // This udp accepts any client and port
    int init(const int portNumber);
    void run() override;
    void stop();

private:
    DFNetwork * _network;
    int _iSocketFD;

};

class UDPSendMessage: public Thread {
// To reduce concurrency overhead, we first put msg into a message queue, and then periodically check the msg queue and send front messages.
public:
    UDPSendMessage();
    ~UDPSendMessage() override;

    int init();

    void run() override;

    void stop();

    int AddMessage(const std::string & ip, int port, const std::string & message);

    struct QueueData {
        std::string ip;
        int port;
        std::string message;
    };

private:
    // send it in run function
    void sendMessage(const std::string & ip, int port, const std::string & message);

    ConcurrentQueue<QueueData> _queue;
    int _iSocketFD;

};
}



#endif //UDP_HPP
