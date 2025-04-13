//
// Created by zbguo on 3/18/25.
//

#include "pnode.hpp"

#include <iostream>

namespace paxosdb {
    PNode::PNode(): _node_id(0) {

    }
    // TODO: need to remove the running process here
    PNode::~PNode() = default;




    int PNode::initNetwork(const Options& options, Network *& network) {
        int ret = _network.init(options.oSingleNode.GetNodeIPAddress(), options.oSingleNode.GetNodePort(), 1); // TODO: numIOThread can be extended
        if (ret < 0) {
            std::cerr << "PNode::initNetwork() failed: " << ret << std::endl;
            return ret;
        }
        network = &_network;
        return 0;

    }

    int PNode::init(const Options &options, Network *&network) {
        int ret = 0;

        ret = initNetwork(options, network);
        if (ret < 0) {
            std::cerr << "PNode::initNetwork() failed in init(): " << ret << std::endl;
            return ret;
        }


        return 0;
    }


    int PNode::onReceiveMessage(const char *message, size_t message_size) {
        return 0;
    }

}
