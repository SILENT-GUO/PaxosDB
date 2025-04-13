//
// Created by zbguo on 3/18/25.
//

#ifndef PNODE_HPP
#define PNODE_HPP

#pragma once
#include <node.hpp>
#include <network.hpp>

#include "network/DFNetwork.hpp"

namespace paxosdb {

class PNode final : public Node {
public:
    PNode();
    ~PNode() override;

    int init(const Options &options, Network *&network) ;

    int onReceiveMessage(const char* message, size_t message_size) override;

private:
    int initNetwork(const Options& options, Network *& network);
    DFNetwork _network;
    node_id_t _node_id;

};



}



#endif //PNODE_HPP
