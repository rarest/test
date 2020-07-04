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

bool duplicate2(const int *numbers, int length, int *duplicate) {
    if (!numbers || length <= 1) return false;

    int start = 1;
    int end = length - 1;
    bool find = false;

    while (end >= start) {
        int middle = (end - start) >> 2 + start;
        int count = countRange(numbers, length, start, middle);
        if (end == start) {
            if (count <= 1) {
                break;
            } else {
                *duplicate = numbers[start];
                find = true;
            }
            break;
        }
        if (count > middle - start + 1) {
            end = middle;
        } else {
            start = middle;
        }
    }
    return find;
}

int countRange(const int *numbers, int length, int start, int end) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= start && numbers[i] <= end)
            count++;
    }
    return count;
}
