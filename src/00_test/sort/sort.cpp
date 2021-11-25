//
// Created by ChenShuQuan on 2021/11/25.
//
#include "sort.h"

int bubbleSort(int *data, int n) {
    if (!data || n <= 1)
        return -1;
    bool is_swap = false;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n - i; j++) {
            if (data[j - 1] > data[j]) {
                std::swap(data[j - 1], data[j]);
                is_swap = true;
            }
        }
        if (!is_swap)
            break;
    }
    return 0;
}

int insertSort(int *data, int n) {
    if (!data || n <= 1)
        return -1;
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && data[j] < data[j - 1]; j--) {
            std::swap(data[j - 1], data[j]);
        }
    }
    return 0;
}

int selectSort(int *data, int n) {
    if (!data || n <= 1)
        return -1;
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[idx]) {
                idx = j;
            }
        }
        std::swap(data[i], data[idx]);
    }
    return 0;
}

int quickSort(int *data, int left, int right) {
    if (!data || left >= right)
        return -1;
    int key = data[left];
    int start = left, end = right;
    while (start < end) {
        while (start < end && data[end] >= key) --end;
        data[start] = data[end];
        while (start < end && data[start] <= key) ++start;
        data[end] = data[start];
    }
    data[start] = key;
    quickSort(data, left, start);
    quickSort(data, start + 1, right);
    return 0;
}

void mergeCount(int *data, int left, int mid, int right) {
    int *tmp = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (data[i] < data[j])
            tmp[k++] = data[i++];
        else
            tmp[k++] = data[j++];
    }
    while (i <= mid)
        tmp[k++] = data[i++];
    while (j <= right)
        tmp[k++] = data[j++];
    for (int i = 0; i < k; ++i) {
        data[left + i] = tmp[i];
    }
    delete[] tmp;
}

int mergeSort(int *data, int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    mergeCount(data, left, mid, right);
    return 0;
}