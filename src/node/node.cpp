//
// Created by zbguo on 3/18/25.
//
#include "node.hpp"
#include "network.hpp"

namespace paxosdb {
    node_id_t SingleNodeInfo::nextNodeID = 0;
    int Node::RunNode(const Options &oOptions, Node *&oPNode) {
        oPNode = nullptr; // clear it first

    }

}
