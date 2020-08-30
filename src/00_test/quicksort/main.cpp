#include <iostream>
#include <random>
#include <ctime>
#include <mutex>

void randSeed() {
    static std::once_flag onceFlag;
    std::call_once(onceFlag, [] { srand(time(nullptr)); });
}


int partition(int *data, int start, int end) {
    if (start == end) return start;
    int pos = rand() % (end - start + 1) + start;
    std::swap(data[end], data[pos]);
    pos = start;
    int key = data[start];
    for (int i = start + 1; i <= end; i++) {
        if (data[i] < key) {
            pos++;
            if (pos != i)
                std::swap(data[i], data[pos]);
        }
    }
    std::swap(data[pos], data[start]);
    return pos;
}


void quickSortCore(int *data, int start, int end) {
    if (start == end) return;
    int mid = partition(data, start, end);
    if (mid > start)
        quickSortCore(data, start, mid - 1);
    if (mid < end)
        quickSortCore(data, mid + 1, end);
}

void quickSort(int *data, int length) {
    if (data == nullptr || length <= 0) return;
    randSeed();
    quickSortCore(data, 0, length - 1);
}


int main() {
    int testData[10];
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 10; j++) {
            testData[j] = rand() % 100;
            printf("%d ", testData[j]);
        }
        printf("\n");
        quickSort(testData, 10);
        for (int j = 0; j < 10; j++) {
            printf("%d ", testData[j]);
        }
        printf("\n");
    }

}