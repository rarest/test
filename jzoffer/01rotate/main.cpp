#include "rotate.h"
#include <memory>
#include <iostream>
#include <iomanip>

using namespace std;

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
}


int main() {
    int h = 4, w = 5;
    shared_ptr<uint8_t> data = init_matrix(w, h);
    print_matrix(data.get(), w, h);

    rotate90_clockwise(data.get(),w,h);
    print_matrix(data.get(),w,h);
    rotate90_anticlockwise(data.get(),w,h);
    print_matrix(data.get(),w,h);

}