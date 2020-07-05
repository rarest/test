//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

int main() {
    int matrix[][4] = {
            {1, 2, 8,  9},
            {2, 4, 9,  12},
            {4, 7, 10, 13},
            {6, 8, 11, 15}
    };
    int test[] = {1, 2, 4, 5, 15, 16};
    int length = sizeof(test) / sizeof(int);
    for (int i = 0; i < length; i++) {
        bool ret = find((int *) matrix, 4, 4, test[i]);
        printf("find %d ret %d \n", test[i], ret);
    }
    return 0;
}