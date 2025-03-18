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

    virtual void initNetworkThreads() = 0; // call this function before send / recv messages
    virtual void stopNetworkThreads() = 0;
private:
    Node * oNode;
};


}

#endif //NETWORK_HPP
