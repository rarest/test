//
// Created by Chen Shuquan on 2021/12/6.
//

#include "ThreadPool4.h"

#include <utility>

ThreadPoo4::ThreadPoo4(size_t size) : stop_(false) {
    start(size);
}

ThreadPoo4::ThreadPoo4(size_t size,
                       std::function<void(int)> on_thread_create,
                       std::function<void(int)> on_thread_destroy) : stop_(false),
                                                                     on_thread_create_(std::move(on_thread_create)),
                                                                     on_thread_destroy_(std::move(on_thread_destroy)) {
    start(size);
}

ThreadPoo4::~ThreadPoo4() {
    {
        std::unique_lock<std::mutex> lock(mutex_);
        stop_ = true;
        task_cond_.notify_all();
    }
    for (size_t i = 0; i < pool_.size(); ++i) {
        pool_[i]->join();
    }
}

bool ThreadPoo4::enqueue(const std::function<void()> &task) {
    auto t = std::make_shared<std::function<void()>>(task);
    if (!task_queue_.enqueue(t)) {
        return false;
    }
    {
        std::unique_lock<std::mutex> lock(mutex_);
        task_cond_.notify_one();
    }
    return true;
}

void ThreadPoo4::execute(int index) {
    if (on_thread_create_) {
        on_thread_create_(index);
    }
    while (!stop_.load()) {
        std::shared_ptr<std::function<void()>> f;
        while (!stop_.load() && task_queue_.try_dequeue(f)) {
            (*f.get())();
            f.reset();
        }

        {
            std::unique_lock<std::mutex> lock(mutex_);
            if (!stop_.load()) {
                task_cond_.wait(lock);
            }
        }
    }
    if (on_thread_destroy_) {
        on_thread_destroy_(index);
    }
}

void ThreadPoo4::start(size_t size) {
    for (size_t i = 0; i < size; ++i) {
        auto t = make_shared<std::thread>(std::bind(&ThreadPoo4::execute, this, (int) i));
        pool_.push_back(t);
    }
}