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
        pBegin = pEnd = pData;
        while (*pBegin != '\0') {
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


    char*  left_rotate_string(char* pData, int n) {
        if(pData) {
            int nLength =  strlen(pData);
            if(nLength > 0 && n > 0 && n < nLength) {
                char* firstStart = pData;
                char* firstEnd = pData + n -1;
                char* secondStart = pData + n;
                char* secondEnd = pData + nLength - 1;
                //翻转字符串的前面 n 个字符
                reverse_region(firstStart, firstEnd);
                //翻转字符串的后面部分
                reverse_region(secondStart, secondEnd);
                //翻转整个字符串
                reverse_region(firstStart, secondEnd);
            }
        }

        return pData;
    }
END_INTERVIEW_NMS