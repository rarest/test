//
// Created by Chen Shuquan on 2020/5/13.
//

#ifndef INTERVIEW_THREADPOOL1_H
#define INTERVIEW_THREADPOOL1_H

#include <mutex>
#include <condition_variable>
#include <atomic>
#include <functional>
#include <future>
#include <vector>
#include <queue>

class ThreadPool1 {
public:
    ~ThreadPool1() = default;
    void start();
    void addJob(std::function<void()> job);
    void waitFinish();
    bool taskRunning();
    static ThreadPool1 *getInstance();

private:
    ThreadPool1();
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
    static ThreadPool1 *instance;
    static std::mutex instanceMutex;
};


#endif //INTERVIEW_THREADPOOL1_H
