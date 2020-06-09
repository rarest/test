//
// Created by Chen Shuquan on 2020/6/4.
//

#include "ThreadPool3.h"
using namespace interview;

ThreadPool3::ThreadPool3(int size) : m_size(size), m_isStarted(false) {
    start();
}

ThreadPool3::~ThreadPool3() {
    if (m_isStarted) stop();
}

void ThreadPool3::start() {
    m_isStarted = true;
    for (int i = 0; i < m_size; i++) {
        m_threads.push_back(new std::thread([this] { threadLoop(); }));
    }
}

void ThreadPool3::stop() {
    LOG(debug, "thread_pool::stop() stop.");
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_isStarted = false;
        m_condition.notify_all();

        LOG(debug, "thread_pool::stop() notifyAll().");
    }
    for (int i = 0; i < m_size; i++) {
        m_threads[i]->join();
        delete m_threads[i];
    }
    m_threads.clear();
}

void ThreadPool3::addTask(const ThreadPool3::Task &task) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_taskQueue.push(std::make_pair(kPriority_level2, task));
    m_condition.notify_one();

}

void ThreadPool3::addTaskPair(const ThreadPool3::TaskPair &taskPair) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_taskQueue.push(taskPair);
    m_condition.notify_one();
}

void ThreadPool3::threadLoop() {
    LOG(debug, "thread_pool::threadLoop() tid : " + interview::get_tid() + " start.");
    while (m_isStarted) {
        const Task task = take();
        if (task) task();
    }
    LOG(debug, "thread_pool::threadLoop() tid : " + get_tid() + " exit.");
}

ThreadPool3::Task ThreadPool3::take() {
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_taskQueue.empty() && m_isStarted) {
        LOG(debug, "thread_pool::take() tid : " + get_tid() + " wait.");
        m_condition.wait(lock);
    }
    LOG(debug, "thread_pool::take() tid : " + get_tid() + " wakeup.");
    Task task;
    TaskQueue::size_type size = m_taskQueue.size();
    if (!m_taskQueue.empty() && m_isStarted) {
        task = m_taskQueue.top().second;
        m_taskQueue.pop();

    }
    return task;
}
