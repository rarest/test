//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"
#include <stdexcept>

int min(int *num, int len) {
    if (!num || len < 1)
        throw std::invalid_argument("invalid param");
    int start = 0;
    int end = len - 1;
    int mid = 0;
    while (num[start] >= num[end]) {
        if (end - start == 1) {
            mid = end;
            break;
        }
        mid = (start + end) / 2;
        if (num[start] == num[mid] && num[mid] == num[end]) {
            int min = num[start];
            for (int i = start; i <= end; i++) {
                if (min > num[i])
                    min = num[i];
            }
            return min;
        }
        if (num[mid] >= num[start])
            start = mid;
        else if (num[mid] <= num[end])
            end = mid;
    }

    return num[mid];
}