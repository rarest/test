//
// Created by Chen Shuquan on 2020/5/11.
//

#ifndef INTERVIEW_REVERSE_STENTENCE_H
#define INTERVIEW_REVERSE_STENTENCE_H

#include "common.h"

BEGIN_INTERVIEW_NMS
    /**
     *  abc -> cba
     * @param pBegin
     * @param pEnd
     */
    void reverse_region(char *pBegin, char *pEnd);
    /**
     *   i am a student.  student. a am i
     * @param pData
     * @return
     */
    char *reverse_sentence(char *pData);

    /**
     * abcdefg 2  ->  cdefgab
     * bagfedc ->cdefgab
     *
     * @param pStr
     * @param n
     * @return
     */
    char* left_rotate_string(char *pStr, int n);

END_INTERVIEW_NMS
#endif //INTERVIEW_REVERSE_STENTENCE_H
