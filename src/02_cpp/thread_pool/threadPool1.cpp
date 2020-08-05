//
// Created by Chen Shuquan on 2020/5/13.
//

#include "threadPool1.h"


#include <thread>
#include <iostream>
#include <mutex>

static std::once_flag g_once_flag;
ThreadPool1 *ThreadPool1::instance = nullptr;
std::mutex ThreadPool1::instanceMutex;

void ThreadPool1::start() {
    if (alive || runningJobs > 0 || aliveThreads > 0) return;
    pool.clear();
    alive = true;
    aliveThreads = 0;
    printf("threading pool size %u\n", threadNum);
    for (decltype(threadNum) ii = 0; ii < threadNum; ii++) {
        pool.emplace_back(std::thread(&ThreadPool1::workingFunction, this));
        aliveThreads += 1;
    }

}

void ThreadPool1::addJob(std::function<void()> job) {
    if (!alive) return;
    {
        std::unique_lock<std::mutex> lock(quequeMutex);
        queue.emplace(job);
    }
    queueCondition.notify_one();

}

void ThreadPool1::waitFinish() {
    std::unique_lock<std::mutex> lock(taskMutex);
    taskCondition.wait(lock, [this] { return !taskRunning(); });
}

bool ThreadPool1::taskRunning() {
    return runningJobs > 0 || !queue.empty();
}

ThreadPool1 *ThreadPool1::getInstance() {
    std::call_once(g_once_flag, [&]() { instance = new ThreadPool1();});
    return instance;
}

void ThreadPool1::workingFunction() {
    std::unique_lock<std::mutex> lock(quequeMutex);
    while (true) {
        if (!queue.empty()) {
            std::function<void()> job = queue.front();
            queue.pop();
            lock.unlock();
            {
                std::unique_lock<std::mutex> lk(taskMutex);
                runningJobs += 1;
            }
            job();
            {
                std::unique_lock<std::mutex> lk(taskMutex);
                runningJobs -= 1;
            }

        } else if (!alive) {
            aliveThreads -= 1;
            taskCondition.notify_one();
            queueCondition.notify_one();
            break;
        } else {
            taskCondition.notify_one();
            queueCondition.wait(lock, [this] { return !this->queue.empty() || !this->alive; });
        }
    }
}


ThreadPool1::ThreadPool1() : threadNum(std::thread::hardware_concurrency()), alive(false), runningJobs(0),
                             aliveThreads(0) {
    start();
}

