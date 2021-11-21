//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"
#include "common.h"

void f(A *) {
    Log("A invoked");
}

void f(B *) {
    Log("B invoked");
}

void f(void *) {
    Log("void* invoked");
}

//前置声明 调用 f(void*)
void testD(D *x) { f(x); }

//头文件 调用 f(A*)
void testC(C *x) { f(x); }