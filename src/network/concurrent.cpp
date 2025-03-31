//
// Created by zbguo on 3/19/25.
//

#include "concurrent.hpp"


static void* threadRun(void* p) {
    auto* thread = static_cast<paxosdb::Thread*>(p);
    thread->run();
    return nullptr;
}

namespace paxosdb {

void Thread::start() {
    this->m_thread = std::thread([this] { return threadRun(this); });
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