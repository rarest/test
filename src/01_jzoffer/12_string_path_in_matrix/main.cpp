//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

int main() {

    char matrix[] = {'a', 'b', 'c', 'd',
                     'e', 'f', 'g', 'h',
                     'i', 'j', 'k', 'l'};

    bool ret = hasPath(matrix, 3, 4, "bcgkj");
    printf("%d", ret);
    LOG(error, "main")
    return 0;
}