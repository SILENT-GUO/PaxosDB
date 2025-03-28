//
// Created by zbguo on 3/18/25.
//

#ifndef OPTION_HPP
#define OPTION_HPP

#pragma once

#include <vector>
#include <string>

namespace paxosdb {
typedef unsigned int node_id_t;
class SingleNodeInfo {
private:
    node_id_t nodeID;
    std::string nodeIPAddress;
    int nodePort;

public:
    static node_id_t nextNodeID;
    SingleNodeInfo() : nodeID(-1), nodePort(-1) {} // default init is allowed, but you should not use it.
    template <typename T>
    SingleNodeInfo(T&& ip, const int port)
        : nodeID(nextNodeID++), nodeIPAddress(std::forward<T>(ip)), nodePort(port) {}
    [[nodiscard]] inline node_id_t GetNodeID() const { return nodeID; }
    [[nodiscard]] const std::string& GetNodeIPAddress() const { return nodeIPAddress; }
    [[nodiscard]] int GetNodePort() const { return nodePort; }
};

typedef std::vector<SingleNodeInfo> NodeInfoList;

class Options {
// contains all configurable params for a node.
public:
    SingleNodeInfo oSingleNode; // required
    NodeInfoList oVecNodeList; // required
};



}

#endif //OPTION_HPP
