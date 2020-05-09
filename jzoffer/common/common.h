//
// Created by HFX on 2020/5/9.
//

#ifndef INTERVIEW_COMMON_H
#define INTERVIEW_COMMON_H
#include <stdint.h>

template<class T>
void swap(T & val1, T&val2){
    T tmp = val1;
    val1 = val2;
    val2 = tmp;
}

#endif //INTERVIEW_COMMON_H
