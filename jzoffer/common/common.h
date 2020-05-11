//
// Created by HFX on 2020/5/9.
//

#ifndef INTERVIEW_COMMON_H
#define INTERVIEW_COMMON_H

#include <stdint.h>
#include <memory>
#include <iostream>
#include <iomanip>

#define BEGIN_INTERVIEW_NMS namespace interview {
#define END_INTERVIEW_NMS }
#define USE_INTERVIEW_NMW using namespace interview;
using namespace std;
BEGIN_INTERVIEW_NMS
    template<class T>
    void swap(T &val1, T &val2) {
        T tmp = val1;
        val1 = val2;
        val2 = tmp;
    }
    template <class T>
    struct SListNode {
        T val;
    };


    shared_ptr<uint8_t> init_matrix(int w, int h);

    void print_matrix(uint8_t *matrix, int w, int h);
END_INTERVIEW_NMS


#endif //INTERVIEW_COMMON_H
