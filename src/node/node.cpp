//
// Created by zbguo on 3/18/25.
//
#include "network.hpp"
#include "pnode.hpp"
#include "node.hpp"

#include <iostream>
#include <ostream>

namespace paxosdb {
    node_id_t SingleNodeInfo::nextNodeID = 0;
    int Node::RunNode(const Options &oOptions, Node *&oPNode) {
        std::cout << "In Node::RunNode" << std::endl;
        oPNode = nullptr; // clear it first
        Network * oPNetwork = nullptr;

        PNode * oPRealNode = new PNode();
        int ret = oPRealNode->init(oOptions, oPNetwork);
        if (ret != 0) {
            delete oPNetwork;
            delete oPRealNode;
            return ret;
        }

        oPNetwork->_oNode = oPRealNode;
        oPNode = oPRealNode;

        oPNetwork->run();

        return 0;

    }



}
