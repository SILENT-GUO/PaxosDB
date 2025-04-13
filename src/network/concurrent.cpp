//
// Created by zbguo on 3/19/25.
//

#include "concurrent.hpp"
#include <iostream>
namespace paxosdb {

Thread::~Thread() {
    if (m_thread.joinable()) {
        std::cout << "[DEBUG] Thread joining in base destructor" << std::endl;
        m_thread.join();  // 或者 detach，但 join 更安全
    }
}


void Thread::start() {
    _isStarted = false;
    m_thread = std::thread([this] {
        _isStarted = true;
        run();
    });

    // 等待线程真正进入 run()
    while (!_isStarted) {
        std::this_thread::yield();
    }
}

void Thread::join() {
    this->m_thread.join();
}

void Thread::detach() {
    this->m_thread.detach();
}

std::thread::id Thread::GetId() const {
    return this->m_thread.get_id();
}

void Thread::sleep(const int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}



}