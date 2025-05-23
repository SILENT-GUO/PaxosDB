//
// Created by zbguo on 3/18/25.
//

#ifndef NETWORK_HPP
#define NETWORK_HPP
#pragma once
namespace paxosdb {

class Node;

class Network {
public:
    Network();
    virtual ~Network();
    virtual void run() = 0;

    void onReceiveMessage(const char* message, unsigned int message_size);
private:
    friend class Node;
    Node * _oNode;
};


}

#endif //NETWORK_HPP
