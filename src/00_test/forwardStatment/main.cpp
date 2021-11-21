//
// Created by ChenShuQuan on 2021/11/21.
//
#include "source.h"

#include "D.h"


int main() {
    //前置声明 调用 f(void*)
    D d;
    testD(&d);
    testD(nullptr);
    //头文件 调用 f(A*)
    C c;
    testC(&c);
    testC(nullptr);


}