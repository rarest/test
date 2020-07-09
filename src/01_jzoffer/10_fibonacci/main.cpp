//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"


int main() {
    LOG(error, "main")
    for (int i = 0; i < 100; i++) {
        long long ret = fibN(i);
        printf("%d %llu\n", i, ret);
    }
    return 0;
}