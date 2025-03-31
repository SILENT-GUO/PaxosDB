//
// Created by zbguo on 3/19/25.
//

#include "udp.hpp"

#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <arpa/inet.h>

namespace paxosdb {

UDPRecvMessage::UDPRecvMessage(DFNetwork *network): _network(network), _iSocketFD(-1), _isRunning(false), _isStopped(false) {

}

UDPRecvMessage::~UDPRecvMessage() {
    if (_iSocketFD != -1) {
        // close socket
        close(_iSocketFD);
        _iSocketFD = -1;
    }
}

void UDPRecvMessage::stop() {
    if (_isRunning) {
        _isStopped = true;
        this->join();
    }
}

// invalid : return -1; normal: return 0;
// config socket connection
int UDPRecvMessage::init(const int portNumber) {
    if ((_iSocketFD = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        return -1;
    }

    sockaddr_in serverAddress{};
    memset(&serverAddress, 0, sizeof(serverAddress));

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(portNumber);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    // REUSEADDR: allow reuse of port if it's in TIME_WAIT status
    setsockopt(_iSocketFD, SOL_SOCKET, SO_REUSEADDR, &serverAddress, sizeof(serverAddress));

    if (bind(_iSocketFD, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) < 0) {
        return -1;
    }

    return 0;
}

void UDPRecvMessage::run() {
    _isRunning = true;
    sockaddr_in serverAddress{};
    socklen_t serverAddressLength = sizeof(serverAddress);

    char msgBuffer[65536];

    while (!_isStopped) {
        struct pollfd fd{};
        fd.fd = _iSocketFD;
        fd.events = POLLIN;

        int result = poll(&fd, 1, 1000);  // timeout = 1000 ms

        if (result == -1) {
            perror("poll error");
            continue;
        }

        if (result == 0) {
            continue;  // timeout, no event
        }

        if (fd.revents & POLLIN) {
            int recvLength = recvfrom(_iSocketFD, msgBuffer, sizeof(msgBuffer), 0,
                                      reinterpret_cast<struct sockaddr*>(&serverAddress),
                                      &serverAddressLength);
            if (recvLength > 0) {
                // Do something with msgBuffer
                _network->onReceiveMessage(msgBuffer, recvLength);
            }
        }
    }
    _isRunning = false;
}


}
