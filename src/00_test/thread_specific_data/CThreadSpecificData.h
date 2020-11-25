//
// Created by Chen Shuquan on 2020/11/25.
//

#ifndef INTERVIEW_CTHREADSPECIFICDATA_H
#define INTERVIEW_CTHREADSPECIFICDATA_H

#include "pthread.h"
#include "stdio.h"

class CThreadSpecificData {
public:
    CThreadSpecificData();
    ~CThreadSpecificData();

public:
    void thread1();
    void thread2();

    static void* rutin1(void*);
    static void* rutin2(void*);

    void test();

private:
    pthread_key_t pthread_key_;
    pthread_t  pthread1_;
    pthread_t pthread2_;
};


#endif //INTERVIEW_CTHREADSPECIFICDATA_H
