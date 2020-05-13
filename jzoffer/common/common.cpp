//
// Created by HFX on 2020/5/9.
//

#include "common.h"

BEGIN_INTERVIEW_NS
    shared_ptr<uint8_t> init_matrix(int w, int h) {
        shared_ptr<uint8_t> matrix(new uint8_t[h * w]);
        for (int i = 0; i < h * w; i++) {
            matrix.get()[i] = i;
        }
        return matrix;
    }

    void print_matrix(uint8_t *matrix, int w, int h) {
        cout.setf(std::ios::right);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                std::cout << right << setw(2) << (int) matrix[i * w + j] << " ";
            }
            std::cout << endl;
        }
        std::cout << endl;
    }

END_INTERVIEW_NS