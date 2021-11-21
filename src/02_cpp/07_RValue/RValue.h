//
// Created by ChenShuQuan on 2021/11/14.
//

#ifndef CPPTEST_RVALUE_H
#define CPPTEST_RVALUE_H

#include <type_traits>
#include <iostream>
#include <string>
#include "common.h"

using namespace std;

template<typename T>
void f(T &&) {
    if (std::is_same<string, T>::value) {
        Log("string");
    } else if (std::is_same<string &, T>::value) {
        Log("string&");
    } else if (std::is_same<string &&, T>::value) {
        Log("string&&");
    } else if (std::is_same<int, T>::value) {
        Log("int");
    } else if (std::is_same<int &, T>::value) {
        Log("int&");
    } else if (std::is_same<int &&, T>::value) {
        Log("int&&");
    } else {
        Log("unkown");
    }
}

void process(int &i) {
    Log("process(int& i) %d", i);
}

void process(int &&i) {
    Log("process(int&& i) %d", i);
}

void myforward(int &&i) {
    Log("myforward(int&& i) %d", i);
    process(std::forward<int>(i));
}

void RunCode(int &&m) {
    cout << "rvalue ref" << endl;
}

void RunCode(int &m) {
    cout << "lvalue ref" << endl;
}

void RunCode(const int &&m) {
    cout << "const rvalue ref" << endl;
}

void RunCode(const int &m) {
    cout << "const lvalue ref" << endl;
}

// 这里利用了universal references，如果写T&,就不支持传入右值，而写T&&，既能支持左值，又能支持右值
template<typename T>
void perfectForward(T &&t) {
    RunCode(forward<T>(t));
}

template<typename T>
void notPerfectForward(T &&t) {
    RunCode(t);
}


#endif //CPPTEST_RVALUE_H
