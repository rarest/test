#include "rotate.h"
#include "common.h"

BEGIN_INTERVIEW_NMS

void rotate90_clockwise(uint8_t *dst, const uint8_t *src, int w, int h) {
    if (!src) return;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dst[h * j + h - 1 - i] = src[i * w + j];
        }
    }

}

void rotate90_anticlockwise(uint8_t *dst, const uint8_t *src, int w, int h) {
    if (!src) return;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            dst[(w - 1 - j) * h + i] = src[i * w + j];
        }
    }
}

void rotate90_clockwise(uint8_t *src, int w, int h) {
    if (!src) return;
}

void rotate90_anticlockwise(uint8_t *src, int w, int h) {
    if (!src) return;
}
END_INTERVIEW_NMS