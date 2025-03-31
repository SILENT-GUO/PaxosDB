//
// Created by zbguo on 3/18/25.
//

#ifndef DFNETWORK_HPP
#define DFNETWORK_HPP

#pragma once

#include <network.hpp>
#include <string>

namespace paxosdb {
class DFNetwork: public Network{
public:
    DFNetwork();
    virtual ~DFNetwork();

    int init(const std::string & ip, const int port, const int numIOThreads);
private:

};
}



#endif //DFNETWORK_HPP
