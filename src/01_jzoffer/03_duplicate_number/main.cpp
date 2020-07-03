//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

int main() {
    LOG(error, "main")

//    int array[] = {2, 3, 1, 0, 4, 5, 6};
    int array[] = {2, 3, 1, 0, 3, 5, 6};
    int length = sizeof(array)/sizeof(int);
    std::cout << "input arry: ";
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << endl;
    int duplicate;
    bool ret = duplicate1(array, length, &duplicate);
    if (ret) {
        printf("find duplicate %d is %d\n", ret, duplicate);
    } else {
        printf("not find\n");
    }
    return 0;
}