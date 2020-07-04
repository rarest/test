//
// Created by HFX on 2020/5/17.
//

#include "printProbability.h"
#include <cstdio>
#include <cmath>
#include <string>
#include <memory.h>

int g_max_value = 6;

void printProbability(int num) {
    if (num < 1) return;
    int maxNum = num * g_max_value;
    int numbers = maxNum - num + 1;
    int *pProb = new int[numbers];
    memset(pProb, 0, numbers);

    probability(num, pProb);

    double totalSceneNum = pow(g_max_value, num);
    for (int i = num; i < maxNum; i++) {
        printf("%d probability %.2f", num, pProb[i - num] / totalSceneNum);
    }
    delete [] pProb;
}

void probability(int num, int* pProbabilities) {
    for(int i = 1; i <=g_max_value; i++) {
        probability(num, num,i,pProbabilities);
    }
}

void probability(int origin, int current, int sum, int* pProbability) {
    if(current ==1) {
        pProbability[sum -origin]++;
    } else{
        for(int i = 1; i<=g_max_value;++i) {
            probability(origin, current-1, i+sum, pProbability);
        }
    }
}