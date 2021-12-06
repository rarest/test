//
// Created by Chen Shuquan on 2021/12/6.
//

#ifndef CPP_TEST_ThreadPoo4_H
#define CPP_TEST_ThreadPoo4_H
#include "concurrentqueue.h"
#include <atomic>
#include <functional>
#include <vector>
#include <thread>
#include <condition_variable>
#include <memory>

class ThreadPoo4 {
public:
    explicit ThreadPoo4(size_t size);
    explicit ThreadPoo4(size_t size,
                        std::function<void(int)> on_thread_create,
                        std::function<void(int)> on_thread_destroy);

    ~ThreadPoo4();

    bool enqueue(const std::function<void()>& task);

private:
    void execute(int index);
    void start(size_t size);

private:
    std::mutex mutex_;
    std::atomic<bool> stop_;
    std::condition_variable task_cond_;
    std::function<void(int)> on_thread_create_;
    std::function<void(int)> on_thread_destroy_;
    std::vector<std::shared_ptr<std::thread>> pool_;
    moodycamel::ConcurrentQueue<std::shared_ptr<std::function<void()>>> task_queue_;

};

#endif //CPP_TEST_ThreadPoo4_H
