//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"


int sumOfNum(int num) {
    int count = 0;
    while (num > 0) {
        count += num % 10;
        num = num / 10;
    }
    return count;
}

bool checkedSum(int row, int col, int threshold) {
    return (sumOfNum(row) + sumOfNum(col)) <= threshold;
}

int moveCountCore(int threshold, int rows, int row, int cols, int col, bool *visited) {
    if (row >= 0 && row < rows && col >= 0 && col < cols && !visited[cols * row + col] &&
        checkedSum(row, col, threshold)) {
        visited[cols * row + col] = true;
        return 1 + moveCountCore(threshold, rows, row - 1, cols, col, visited)
               + moveCountCore(threshold, rows, row + 1, cols, col, visited)
               + moveCountCore(threshold, rows, row, cols, col - 1, visited)
               + moveCountCore(threshold, rows, row, cols, col + 1, visited);
    }
    return 0;
}

int moveCount(int threshold, int rows, int cols) {
    if (threshold < 0 || rows < 1 || cols < 1) return 0;
    bool *visited = new bool[rows * cols];
    memset(visited, 0, rows * cols * sizeof(bool));
    int count = moveCountCore(threshold, rows, 0, cols, 0, visited);
    delete[] visited;
    return count;
}