#include "common.h"

BEGIN_INTERVIEW_NS
/**
 *
 * @param dst
 * @param src
 * @param w
 * @param h
 */
    void rotate90Clockwise(uint8_t *dst, const uint8_t *src, int w, int h);

/**
 *
 * @param dst
 * @param src
 * @param w
 * @param h
 */
    void rotate90AntiClockwise(uint8_t *dst, const uint8_t *src, int w, int h);

/**
 *
 * @param src
 * @param w
 * @param h
 */
    void rotate90_clockwise(uint8_t *src, int w, int h);

/**
 *
 * @param src
 * @param w
 * @param h
 */
    void rotate90_anticlockwise(uint8_t *src, int w, int h);
    void flipH(uint8_t *src, int w, int h);
    void flipV(uint8_t *src, int w, int h);
    void flipD(uint8_t *src, int w, int h);
    void flipD1(uint8_t *src, int w, int h);
END_INTERVIEW_NS