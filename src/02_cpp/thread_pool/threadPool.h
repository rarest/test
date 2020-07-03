//
// Created by Chen Shuquan on 2020/5/13.
//

#ifndef INTERVIEW_THREADPOOL_H
#define INTERVIEW_THREADPOOL_H

#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#include <future>
#include <vector>
#include <queue>

class ThreadPool {
public:
    ~ThreadPool() = default;
    void start();
    void addJob(std::function<void()> job);
    void waitFinish();
    bool taskRunning();
    static ThreadPool *getInstance();

private:
    ThreadPool();
    unsigned int threadNum;
    std::vector<std::thread > pool;
    std::atomic<bool> alive;
    std::queue<std::function<void() > >queue;
    std::mutex quequeMutex;
    std::condition_variable queueCondition;

    std::atomic<int> runningJobs;
    std::atomic<int> aliveThreads;

    std::mutex taskMutex;
    std::condition_variable taskCondition;

    void workingFunction();
    static ThreadPool *instance;
    static std::mutex instanceMutex;
};


#endif //INTERVIEW_THREADPOOL_H
