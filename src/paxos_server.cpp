//
// Created by zbguo on 3/18/25.
//

#include "paxos_server.hpp"

#include <iostream>
#include <option.hpp>
#include <ostream>

namespace paxos_echo {

    int PaxosServer::RunPaxosServer() {
        // init each variables in server as an option instance.
        paxosdb::Options options;
        options.oSingleNode = this->oSingleNode;
        options.oVecNodeList = this->oVecNodeList;

        int ret = paxosdb::Node::RunNode(options, this->oPaxosNode);
        if (ret != 0) {
            std::cerr << "paxosdb::Node::RunNode failed" << std::endl;
            return ret;
        }

        return 0;
    }

}
