//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"

void testDuplicate1() {
    //    int array[] = {2, 3, 1, 0, 4, 5, 6};
    int array[] = {2, 3, 1, 0, 3, 5, 6};
    int length = sizeof(array) / sizeof(int);
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
}

void testDuplicate2() {
    int array[] = {2, 3, 5, 4, 3, 4, 6, 7};
    int length = sizeof(array) / sizeof(int);
    std::cout << "input array: ";
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
}

int main() {
    LOG(error, "main")
    testDuplicate1();
    testDuplicate2();

    return 0;
}