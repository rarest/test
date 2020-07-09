//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"

long long fibN(int n) {
    long long fib[2]{0, 1};
    if (n < 2)
        return fib[n];
    long long ret = 0;
    for (int i = 2; i <= n; i++) {
        ret = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = ret;
    }
    return ret;
}