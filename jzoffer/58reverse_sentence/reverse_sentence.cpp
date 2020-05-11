//
// Created by Chen Shuquan on 2020/5/11.
//
#include "reverse_stentence.h"

BEGIN_INTERVIEW_NMS

    void reverse_region(char *pBegin, char *pEnd) {
        if (!pBegin || !pEnd) return;
        while (pBegin < pEnd) {
            interview::swap(*pBegin++, *pEnd--);
        }
    }

    char *reverse_sentence(char *pData) {
        if (!pData) return nullptr;
        char *pBegin = pData;
        char *pEnd = pData;
        while (*pEnd != '\0') {
            pEnd++;
        }
        pEnd--;

        reverse_region(pBegin, pEnd);

        while (*pEnd != '\0') {
            if (*pBegin == ' ') {
                pBegin++;
                pEnd++;
            } else if (*pEnd == ' ' || *pEnd == '\0') {
                reverse_region(pBegin, --pEnd);
                pBegin = ++pEnd;
            } else {
                pEnd++;
            }
        }
        return pData;
    }
END_INTERVIEW_NMS