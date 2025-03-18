//
// Created by zbguo on 3/18/25.
//

#pragma once

#ifndef PAXOS_SERVER_HPP
#define PAXOS_SERVER_HPP
#include <node.hpp>

namespace paxos_echo {

class PaxosServer {
public:
    PaxosServer() = delete;
    PaxosServer(const paxosdb::SingleNodeInfo & singleNode, const paxosdb::NodeInfoList & vecNodeList);
    ~PaxosServer();

    int RunPaxosServer(); // complete the variable options, and pass to runNode.

private:
    paxosdb::SingleNodeInfo oSingleNode; // single node info object;
    paxosdb::NodeInfoList oVecNodeList;

    paxosdb::Node *oPaxosNode;
};


}



#endif //PAXOS_SERVER_HPP
