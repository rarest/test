//
// Created by ChenShuQuan on 2021/11/25.
//
#include "sort.h"
#include "common.h"

void print(int *data, int n) {
    printf("List: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {22, 3, 24, 3, 2, 3, 23, 14, 37, 28, 11, 9, 17, 38};
    int n = sizeof(a) / sizeof(int);
    print(a, n);


//    mergeSort(a, 0, n - 1);
//    quickSort(a, 0, n - 1);
//    selectSort(a, n);
//    insertSort(a, n);
//    bubbleSort(a, n);
    print(a, n);


}