//
// Created by zbguo on 3/16/25.
//

#ifndef NODE_HPP
#define NODE_HPP

#pragma once


#include "option.hpp"

namespace paxosdb {

class Node {
    // this is a node parent class.
public:
    Node() = default;
    virtual ~Node() = default;

    // key function 1: we should directly call this function in parent class. It will instantiate a child instance and pass it to the parent pointer (polymorphism)
    // Things to do here: instantiate a opNode, init the network
    static int RunNode(const Options &oOptions, Node *& oPNode);
};

}

#endif //NODE_HPP
