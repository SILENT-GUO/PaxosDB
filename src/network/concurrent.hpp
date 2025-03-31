//
// Created by zbguo on 3/19/25.
//

#ifndef CONCURRENT_HPP
#define CONCURRENT_HPP

#pragma once
#include <condition_variable>
#include <deque>
#include <thread>

#include "NonCopyable.hpp"


namespace paxosdb {

class Thread: public NonCopyable {
    // this class will be mostly a re-implementation of std::thread.
public:
    Thread() = default;
    virtual ~Thread() = default;
    void start(); // this function directly call run() method. Similar to the node / pnode scenerio, user can directly use Thread.start() to implement alternative run methods
    void join();
    void detach();

    [[nodiscard]] std::thread::id GetId() const;

    virtual void run() = 0;
    static void sleep(int ms);
private:
    std::thread m_thread;
};

template<class T>
class ConcurrentQueue {
public:
    ConcurrentQueue(): _size(0) {}
    virtual ~ConcurrentQueue() = default;
    T& peek() {
        // retrieve the first element
        std::unique_lock<std::mutex> lock(_lock);
        _cond.wait(lock, [this]{return !_queue.empty();});
        return _queue.front();
    }

    void pop() {
        std::unique_lock<std::mutex> lock(_lock);
        if (!_queue.empty()) {
            _queue.pop_front();
            --_size;
        }
    }

    size_t push(const T& t, const bool signal = true, const bool isBack = true) {
        // by default insert in the back.
        std::unique_lock<std::mutex> lock(_lock);
        if (isBack) {
            _queue.push_back(t);
        } else {
            _queue.push_front(t);
        }
        if (signal) {
            _cond.notify_one();
        }

        return ++_size;
    }

    bool empty() {
        std::unique_lock<std::mutex> lock(_lock);
        return _queue.empty();
    }

    [[nodiscard]] size_t size() {
        std::unique_lock<std::mutex> lock(_lock);
        return _size;
    }
private:
    size_t _size;
    std::condition_variable_any _cond;
    std::deque<T> _queue;
    std::mutex _lock;
};

}




#endif //CONCURRENT_HPP
