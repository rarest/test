#include "rotate.h"
USE_INTERVIEW_NS
int main() {
    int h = 4, w = 5;
    shared_ptr<uint8_t> data = init_matrix(w, h);
    print_matrix(data.get(), w, h);
    shared_ptr<uint8_t> dst = init_matrix(w, h);
    rotate90Clockwise(dst.get(), data.get(), w, h);
    print_matrix(dst.get(), h, w);
    rotate90AntiClockwise(dst.get(), data.get(), w, h);
    print_matrix(dst.get(), h, w);

}
