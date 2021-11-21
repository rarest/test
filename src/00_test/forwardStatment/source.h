//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

#include  "common.h"

//forward declaration
struct B;
struct D;

//include head file
#include "C.h"

void f(A *);
void f(B *);
void f(void *);
//前置声明 调用 f(void*)
void testD(D *d);
//头文件 调用 f(A*)
void testC(C *c);


#endif //INTERVIEW_SOURCE_H
