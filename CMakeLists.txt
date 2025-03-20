cmake_minimum_required(VERSION 3.10)
project(paxosDB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include/)

add_executable(PaxosDBSampleApplication application/main.cpp
        src/paxos_server.cpp
        src/paxos_server.hpp
        src/node/node.cpp
        include/option.hpp
        src/node/pnode.cpp
        src/node/pnode.hpp
        include/network.hpp
        src/network/network.cpp
        src/network/DFNetwork.cpp
        src/network/DFNetwork.hpp
        src/network/concurrent.cpp
        src/network/concurrent.hpp
        include/NonCopyable.hpp
        src/network/udp.cpp
        src/network/udp.hpp)
