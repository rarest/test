//
// Created by Chen Shuquan on 2020/5/11.
//


#include "reverse_stentence.h"

USE_INTERVIEW_NMW

int main() {

    char p[] = "i am a student.";

    printf("input sentence: %s\n", p);
    char* result = reverse_sentence(p);
    printf("output sentence: %s\n", result);


    char p1[] = "abc, 123, 456, 789";
    printf("input sentence: %s\n", p1);
    char* result1 = reverse_sentence(p1);
    printf("output sentence: %s\n", result1);


    return 0;
}