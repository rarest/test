//
// Created by Chen Shuquan on 2020/6/2.
//

#ifndef INTERVIEW_THREADPOOL2_H
#define INTERVIEW_THREADPOOL2_H

#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>
#include <vector>

class ThreadPool2 {
    size_t m_size;
    bool m_stop;
    std::mutex m_mutex;

public:
    ThreadPoolAdvance(size_t size_):size(size_){}

};



#endif //INTERVIEW_THREADPOOL2_H
