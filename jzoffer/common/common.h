//
// Created by HFX on 2020/5/9.
//

#ifndef INTERVIEW_COMMON_H
#define INTERVIEW_COMMON_H
#include <stdint.h>

#define BEGIN_INTERVIEW_NMS namespace interview {
#define END_INTERVIEW_NMS }
#define USE_INTERVIEW_NMW using namespace interview;

template<class T>
void swap(T & val1, T&val2){
    T tmp = val1;
    val1 = val2;
    val2 = tmp;
}



#endif //INTERVIEW_COMMON_H
