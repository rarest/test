//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"

bool duplicate1(int numbers[], int length, int *duplicate) {
    if (numbers == nullptr || length <= 0) {
        return false;
    }

    for (int i = 0; i < length; i++) {
        if (numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }

    for (int i = 0; i < length; i++) {
        while (numbers[i] != i) {
            if (numbers[i] == numbers[numbers[i]]) {
                *duplicate = numbers[i];
                return true;
            }
            swap(numbers[i], numbers[numbers[i]]);
        }
    }

    return false;
}