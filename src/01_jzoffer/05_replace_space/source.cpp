//
// Created by Chen Shuquan on 2020/7/3.
//

#include "source.h"

void replace_space(char *src, int length) {
    if (!src || length < 1);
    int i = 0;
    int numOfSpace = 0;
    int srcLen = 0;
    while (src[i] != '\0') {
        srcLen++;
        if (src[i] == ' ')
            numOfSpace++;
        i++;
    }
    int newStrLen = srcLen + numOfSpace * 2;
    if (newStrLen > length) return;
    int strIdx = srcLen;
    int newStrIdx = newStrLen;
    while (strIdx >= 0) {
        if (src[strIdx] == ' ') {
            src[newStrIdx--] = '0';
            src[newStrIdx--] = '2';
            src[newStrIdx--] = '%';
        } else {
            src[newStrIdx--] = src[strIdx];
        }
        strIdx--;
    }
}
