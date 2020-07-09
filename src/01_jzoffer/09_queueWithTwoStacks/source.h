//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

#include "common.h"

#include <stack>

template<class T>
class queue {
public:
    queue();

    ~queue();

public:
    void appendTail(const T &val);

    T deleteHead();

private:

    std::stack<T> stack1;
    std::stack<T> stack2;

};

template<class T>
queue<T>::queue() {
}

template<class T>
queue<T>::~queue() {
}

template<class T>
void queue<T>::appendTail(const T &val) {
    stack1.push(val);
}

template<class T>
T queue<T>::deleteHead() {
    if (stack2.empty()) {
        while (!stack1.empty()) {
            T val = stack1.top();
            stack1.pop();
            stack2.push(val);
        }
    }
    if (stack2.empty())
        throw std::invalid_argument("invalid param");

    T val = stack2.top();
    stack2.pop();
    return val;
}


#endif //INTERVIEW_SOURCE_H
