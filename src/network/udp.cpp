//
// Created by zbguo on 3/19/25.
//

#include "udp.hpp"

#include <unistd.h>

namespace paxosdb {

UDPRecvMessage::UDPRecvMessage(DFNetwork *network): _network(network), _iSocketFD(-1) {

}

UDPRecvMessage::~UDPRecvMessage() {
    if (_iSocketFD != -1) {
        // close socket
        close(_iSocketFD);
        _iSocketFD = -1;
    }
}

void UDPRecvMessage::stop() {
    
}

}
