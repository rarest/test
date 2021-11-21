//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

#include "common.h"


class SingletonTest : public SingletonBaseLazy<SingletonTest> {
public:
    void test() {
        printf("test hello world\n");
    }
};


class SingletonSample {
private:
    SingletonSample() = default;
    SingletonSample(const SingletonSample&) = delete;
    SingletonSample& operator=(const SingletonSample&) = delete;
    ~SingletonSample() = default;


public:
    static SingletonSample& Instance() {
        static SingletonSample singletonSample;
        return singletonSample;
    }

public:
    void test() {
        printf("print Singleton Test\n");
    }

};

class SingletonTest111 {
    SINGLETON_CTOR(SingletonTest111);
public:
    static SingletonTest111 &Instance() {
        static std::once_flag s_flag;
        std::call_once(s_flag, [&]() {
            _ptr = new SingletonTest111;
        });

        return *_ptr;
    }

    void test() {
        printf("test hello world");
    }

private:
    static SingletonTest111 *_ptr;
//    static std::mutex m_cs;
};



#endif //INTERVIEW_SOURCE_H
