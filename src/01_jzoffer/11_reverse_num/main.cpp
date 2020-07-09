//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

bool Test(int val, int exp) {
    if (val == exp)
        printf("pass\n");
    else
        printf("failed\n");
}

int main() {
    LOG(error, "main")

    int array3[] = {4, 5, 1, 2, 3};
    int ret = min(array3, 5);
    Test(ret, 1);

    int array[] = {3, 4, 5, 1, 2};

    int array2[] = {1, 1, 1, 0, 1};
    ret = min(array, 5);
    Test(ret, 1);

    ret = min(array2, 5);
    Test(ret, 0);



    return 0;


}