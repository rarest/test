#include "rotate.h"
USE_INTERVIEW_NMW
int main() {
    int h = 4, w = 5;
    shared_ptr<uint8_t> data = init_matrix(w, h);
    print_matrix(data.get(), w, h);
    shared_ptr<uint8_t> dst = init_matrix(w, h);
    rotate90_clockwise(dst.get(), data.get(), w, h);
    print_matrix(dst.get(), h, w);
    rotate90_anticlockwise(dst.get(), data.get(), w, h);
    print_matrix(dst.get(), h, w);

}
