//
// Created by zbguo on 3/16/25.
//
#include <cstring>
#include <iostream>
#include "node.hpp"

using namespace paxosdb;

std::pair<std::string, int> parseIpPort(const std::string& input) {
    const size_t pos = input.find(':');
    if (pos == std::string::npos) {
        throw std::invalid_argument("Invalid IP:Port format in parseIpPort: " + input);
    }
    std::string ip = input.substr(0, pos);
    int port = std::stoi(input.substr(pos + 1));
    return {ip, port};
}

void parseAllIpPort(const char* input, NodeInfoList& vecNodeList, const SingleNodeInfo& currentNode) {
    std::string sTmpStr;
    const size_t iStrLen = strlen(input);

    for (int i = 0; i < iStrLen; i++) {
        if (input[i] == ',' || i == iStrLen - 1) {
            if (i == iStrLen - 1 && input[i] != ',') {
                sTmpStr += input[i];
            }

            try {
                auto [nodeIP, nodePort] = parseIpPort(sTmpStr);

                // **🔍 Check if it's the same as currentNode**
                if (nodeIP == currentNode.GetNodeIPAddress() && nodePort == currentNode.GetNodePort()) {
                    std::cout << "Skipping current node: " << nodeIP << ":" << nodePort << std::endl;
                } else {
                    vecNodeList.emplace_back(nodeIP, nodePort);
                }
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << " in entry: " << sTmpStr << std::endl;
                return;
            }

            sTmpStr.clear();
        } else {
            sTmpStr += input[i];
        }
    }
}






int main (const int argc, const char * argv[]) {
    if (argc < 3) {
        printf("%s <myip:myport> <node0_ip:node_0port,node1_ip:node_1_port,node2_ip:node2_port,...>\n", argv[0]);
        return -1;
    }
    auto [myIP, myPort] = parseIpPort(argv[1]);
    const SingleNodeInfo currentNode(myIP, myPort);

    std::cout << currentNode.GetNodeID() << " " << currentNode.GetNodeIPAddress() << " " << currentNode.GetNodePort() << std::endl;

    NodeInfoList vecNodeList;
    vecNodeList.push_back(currentNode);
    parseAllIpPort(argv[2], vecNodeList, currentNode);
    for (auto& node : vecNodeList) {
        std::cout << node.GetNodeID() << " " << node.GetNodeIPAddress() << " " << node.GetNodePort() << std::endl;
    }


}