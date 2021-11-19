//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"
#include "common.h"

struct B {
};
struct D : B {

};

void f(B *) {
    Log("B");
}

void f(void *) {
    Log("void*");
}

// calls f(B*)
void test(D *x) { f(x); }