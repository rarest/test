//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

void test_replace_space() {
    const int length = 100;
    char test[length] = "we are happy!";
    printf("test str before %s\n", test);
    replace_space(test, 100);
    printf("test str after %s\n", test);
}

int main() {
    LOG(error, "main")
    test_replace_space();
    return 0;
}