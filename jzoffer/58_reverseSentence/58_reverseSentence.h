//
// Created by Chen Shuquan on 2020/5/11.
//

#ifndef INTERVIEW_58_REVERSESENTENCE_H
#define INTERVIEW_58_REVERSESENTENCE_H

#include "common.h"
/**
 *  reverse sentence
 */
BEGIN_INTERVIEW_NS
    /**
     *  abc -> cba
     * @param pBegin
     * @param pEnd
     */
    void reverseRegion(char *pBegin, char *pEnd);
    /**
     *   i am a student.  student. a am i
     * @param pData
     * @return
     */
    char* reverseSentence(char *pData);

    /**
     * abcdefg 2  ->  cdefgab
     * bagfedc ->cdefgab
     *
     * @param pStr
     * @param n
     * @return
     */
    char* leftRotateString(char *pStr, int n);

END_INTERVIEW_NS
#endif //INTERVIEW_58_REVERSESENTENCE_H
