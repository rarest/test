#include "rotate.h"
#include "common.h"

BEGIN_INTERVIEW_NS

    /**
     * src[j][h-1-i] = src[i][j]
     * @param dst
     * @param src
     * @param w
     * @param h
     */
    void rotate90Clockwise(uint8_t *dst, const uint8_t *src, int w, int h) {
        if (!src) return;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dst[h * j + h - 1 - i] = src[i * w + j];
            }
        }
    }

    /**
     * src[w-1-j][i] = src[i][j]
     * @param dst
     * @param src
     * @param w
     * @param h
     */
    void rotate90AntiClockwise(uint8_t *dst, const uint8_t *src, int w, int h) {
        if (!src) return;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dst[(w - 1 - j) * h + i] = src[i * w + j];
            }
        }
    }

    /**
     * src[i][j]->src[h-1-i][j];
     * @param src
     * @param w
     * @param h
     */
    void flipH(uint8_t *src, int w, int h) {
        if (!src) return;
        for (int i = 0; i < h / 2; ++i) {
            for (int j = 0; j < w; ++j) {
                swap(src[w * i + j], src[w * (h - 1 - i) + j]);
            }
        }
    }

    /**
     * src[i][j] -> src[i][w-1-j]
     * @param src
     * @param w
     * @param h
     */
    void flipV(uint8_t *src, int w, int h) {
        if (!src) return;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w / 2; ++j) {
                swap(src[w * i + j], src[w * i + w - 1 - j]);
            }
        }
    }

    /**
     * src[i][j]->src[j][i];
     * @param src
     * @param w
     * @param h
     */
    void flipD(uint8_t *src, int w, int h) {
        if (!src) return;
        if (w == h) {
            for (int i = 0; i < h; ++i) {
                for (int j = i; j < w; ++j) {
                    swap(src[w * i + j], src[j * h + i]);
                }
            }
        } else {
            flipD1(src, w, h);
        }
    }

    void flipD1(uint8_t *src, int w, int h) {
        if (!src) return;
        std::unique_ptr<uint8_t[]> data = std::make_unique<uint8_t[]>(w * h);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                data[j * h + i] = src[w * i + j];
            }
        }
        memcpy(src, data.get(), sizeof(uint8_t) * w * h);
    }


    /**
     *  src[j][h-1-i] = src[i][j]
     *
     *  flipH :src[i][j]->src[h-1-i][j];
     *  flipD: src[h-1-i][j]->src[j][h-1-i]
     * @param src
     * @param w
     * @param h
     */
    void rotate90_clockwise(uint8_t *src, int w, int h) {
        if (!src) return;
        flipH(src, w, h);
        flipD1(src, w, h);
    }

    /**
     * src[w-1-j][i] = src[i][j]
     * flipV: src[i][j] -> src[i][w-1-j]
     * flipD: src[i][w-1-j] -> src[w-1-j][i]
     * @param src
     * @param w
     * @param h
     */
    void rotate90_anticlockwise(uint8_t *src, int w, int h) {
        if (!src) return;
        flipV(src, w, h);
        flipD1(src, w, h);
    }
END_INTERVIEW_NS