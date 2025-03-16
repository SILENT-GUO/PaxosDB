//
// Created by zbguo on 3/16/25.
//

#ifndef NODE_HPP
#define NODE_HPP

#pragma once

#include <string>
#include <vector>
#include <utility>

namespace paxosdb {
typedef unsigned int node_id_t;

class SingleNodeInfo {
private:
    node_id_t nodeID;
    std::string nodeIPAddress;
    int nodePort;
    static node_id_t nextNodeID;
public:
    SingleNodeInfo() = delete; // default init is not allowed.
    template <typename T>
    SingleNodeInfo(T&& ip, const int port)
        : nodeID(nextNodeID++), nodeIPAddress(std::forward<T>(ip)), nodePort(port) {}
    [[nodiscard]] node_id_t GetNodeID() const { return nodeID; } // return by value for all primitive types
    [[nodiscard]] const std::string& GetNodeIPAddress() const { return nodeIPAddress; }
    [[nodiscard]] int GetNodePort() const { return nodePort; }
};

node_id_t SingleNodeInfo::nextNodeID = 0;

typedef std::vector<SingleNodeInfo> NodeInfoList;

}

#endif //NODE_HPP
