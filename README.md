# paxosDB
This is an implementation of a distributed database built from scratch using the Paxos consensus algorithm.

## How to build

```shell
mkdir build
cd build
cmake ..
make
./bin/PaxosDBSampleApplication
```


## How to run a sample program
1. Go to ```main.cpp``` in ```/Application``` Folder
2. Run
```shell
    ./PaxosDBSampleApplication <myip:myport> <node0_ip:node_0port,node1_ip:node_1_port,node2_ip:node2_port,...>
```
For example,
```shell
    ./PaxosDBSampleApplication localhost:1111 localhost:2222,localhost:3333
```