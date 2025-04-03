//
// Created by zbguo on 3/19/25.
//

#ifndef UDP_HPP
#define UDP_HPP

#pragma once
#include <atomic>
#include <string>

#include "concurrent.hpp"
#include "DFNetwork.hpp"


namespace paxosdb {

class UDPRecvMessage: public Thread {
public:
    explicit UDPRecvMessage(DFNetwork * network);
    ~UDPRecvMessage() override;

    // This udp accepts any client and port
    int init(int portNumber);
    void run() override;
    void stop();

private:
    DFNetwork * _network;
    int _iSocketFD;
    std::atomic<bool> _isRunning;
    std::atomic<bool> _isStopped;

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

    ConcurrentQueue<QueueData *> _queue;
    int _iSocketFD;
    std::atomic<bool> _isRunning;
    std::atomic<bool> _isStopped;

};
}



#endif //UDP_HPP
