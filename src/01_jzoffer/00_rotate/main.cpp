#include "rotate.h"
#include "common.h"
USE_INTERVIEW_NS
int main() {
    int h = 4, w = 5;

    Log("origin matrix");
    shared_ptr<uint8_t> data = init_matrix(w, h);
    print_matrix(data.get(), w, h);
    shared_ptr<uint8_t> dst = init_matrix(w, h);
    Log("rotate matrix rotate90Clockwise");
    rotate90Clockwise(dst.get(), data.get(), w, h);
    print_matrix(dst.get(), h, w);
    Log("rotate matrix rotate90AntiClockwise");
    rotate90AntiClockwise(dst.get(), data.get(), w, h);
    print_matrix(dst.get(), h, w);

    Log("origin matrix");

    print_matrix(data.get(), w, h);
//    Log("flipH");
//    flipH(data.get(), w, h);
//    print_matrix(data.get(), w, h);
//    Log("flipV");
//    flipV(data.get(), w, h);
//    print_matrix(data.get(), w, h);
//    Log("flipV");
//    flipD1(data.get(), w, h);
//    print_matrix(data.get(), h, w);

    Log("rotate matrix rotate90_clockwise");
    rotate90_clockwise(data.get(), w, h);
    print_matrix(data.get(), h, w);
    Log("rotate matrix rotate90_anticlockwise");
    rotate90_anticlockwise(data.get(), h,w);
    print_matrix(data.get(), w, h);

}
