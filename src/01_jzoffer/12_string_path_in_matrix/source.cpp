//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"

bool hasPathCore(const char *matrix, int rows, int cols, int row, int col, const char *str, int &strlen, bool *visited) {
    if(str[strlen] == '\0')
        return true;
    bool hasPath = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[cols * row + col] == str[strlen] && !visited[cols*row +col]) {
        strlen++;
        visited[cols * row + col] = true;
        hasPath = hasPathCore(matrix, rows, cols, row - 1, col, str, strlen, visited)
                  || hasPathCore(matrix, rows, cols, row + 1, col, str, strlen, visited)
                  || hasPathCore(matrix, rows, cols, row, col - 1, str, strlen, visited)
                  || hasPathCore(matrix, rows, cols, row, col + 1, str, strlen, visited);
        if (!hasPath) {
            strlen--;
            visited[cols * row + col] = false;
        }
    }
    return hasPath;
}

bool hasPath(const char *matrix, int rows, int cols, const char *str) {
    if (!matrix || rows < 1 || cols < 1 || str == nullptr)
        return false;

    bool *visted = new bool[rows * cols];
    memset(visted, 0, rows * cols * sizeof(bool));

    int strLen = 0;
    bool hasPath = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            hasPath = hasPathCore(matrix, rows, cols, i, j, str, strLen, visted);
        }
    }
    return hasPath;
}

