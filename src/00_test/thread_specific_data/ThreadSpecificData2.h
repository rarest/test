//
// Created by Chen Shuquan on 2020/11/25.
//

#ifndef INTERVIEW_THREADSPECIFICDATA2_H
#define INTERVIEW_THREADSPECIFICDATA2_H

#include "pthread.h"

class ThreadSpecificData2 {

public:
    ThreadSpecificData2();
    ~ThreadSpecificData2();


    void run();
private:
    char * str_accumulate(const char* s);
    void process(char *);
    static void str_alloc_key();
    static void str_alloc_key_wrap();
    static void str_alloc_destroy_accu(void* accu);


public:
    static void* routine(void*);
    static void* routine2(void*);
    static pthread_key_t  pthread_key_;
    pthread_t pthread1_;
    pthread_t pthread2_;


};


#endif //INTERVIEW_THREADSPECIFICDATA2_H
