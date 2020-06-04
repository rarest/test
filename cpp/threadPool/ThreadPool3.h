//
// Created by Chen Shuquan on 2020/6/4.
//

#ifndef INTERVIEW_THREADPOOL3_H
#define INTERVIEW_THREADPOOL3_H

#include <thread>
#include <queue>
#include <mutex>
#include <functional>
#include <condition_variable>
#include "common.h"

class ThreadPool3 {
public:
    enum EPriority {
        kPriority_level0,
        kPriority_level1,
        kPriority_level2
    };
    typedef std::function<void()> Task;
    typedef std::pair<EPriority, Task> TaskPair;

    explicit ThreadPool3( int size);
    ~ThreadPool3();
    void start();
    void stop();
    Task take();
    void addTask(const Task& task);
    void addTaskPair(const  TaskPair &taskPair);

private:
    ThreadPool3(const ThreadPool3& threadPool3);
    ThreadPool3& operator=(const ThreadPool3& threadPool3);

    struct TaskPairCmp {
        bool operator()(const TaskPair &taskPair1, const TaskPair &taskPair2) {
            return taskPair1.first > taskPair2.first;
        }
    };
    typedef std::priority_queue<TaskPair, std::vector<TaskPair>, TaskPairCmp> TaskQueue;

    int m_size;
    std::mutex m_mutex;
    std::condition_variable m_condition;
    TaskQueue m_taskQueue;
    std::vector<std::thread *> m_threads;
    bool m_isStarted;

    void threadLoop();
};


#endif //INTERVIEW_THREADPOOL3_H
