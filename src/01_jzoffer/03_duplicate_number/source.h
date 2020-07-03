//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

#include "common.h"

/**
 *  找出数组中重复的数字
 *
 *  在一个长度为n的数组里所有的数字都在0~n-1的范围内
 *  输入 {2,3,1,0,2,5,3} -> 2 or 3
 *

 */


/**
 * 时间复杂度 o(n), 空间复杂度o(1)
 * 把值为i的值都放到i的位置，如果已经存在则重复了
 *
 * @param numbers
 * @param length
 * @param duplicate
 * @return
 */
bool duplicate1(int numbers[], int length, int *duplicate);

bool duplicate2(int numbers[], int length, int *duplicate);

#endif //INTERVIEW_SOURCE_H
