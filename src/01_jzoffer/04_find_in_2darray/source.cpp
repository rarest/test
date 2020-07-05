//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"

bool find(int *matrix, int rows, int cols, int number) {
    bool find = false;
    if (matrix && rows > 0 && cols > 0) {
        int row = 0;
        int col = cols - 1;
        while (row < rows && col >= 0) {
            int val = matrix[cols * row + col];
            if (val == number) {
                find = true;
                break;
            } else if (val > number) {
                col--;
            } else {
                row++;
            }
        }
    }
    return find;
}
