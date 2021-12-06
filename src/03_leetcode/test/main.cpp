//
// Created by Chen Shuquan on 2021/12/1.
//



void rotate90ClockWise(int *dst, const int *src, int w, int h) {
    if (!src || !dst) return;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dst[j * h + h - i - 1] = src[i * w + j];
        }
    }

}

void rotate90AntiClockWise(int *dst, const int *src, int w, int h) {
    if (!src || !dst) return;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            dst[(w - 1 - j) * h + i] = src[i * w + j];
        }
    }
}