//
// Created by Chen Shuquan on 2020/7/3.
//

#ifndef INTERVIEW_SOURCE_H
#define INTERVIEW_SOURCE_H

#include "common.h"

/**
 *  找出数组中重复的数字
 *
 * 1.  在一个长度为n的数组里所有的数字都在0~n-1的范围内
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

/**
 * 2.长度为n+1的数组，所有数字都在1-n的范围内，至少有一个是重复的，请找出任意一个重复的数字，但不能修改输入的数组
 *
 * {2,3,5,4,3,2,6,7} -> 2 or 3
 *
 *
 * 二分法: 把1~n的数字从中间的数字m分为两部分，前者一半为1~m,后者一半为m+1~n。 如果1~m的数字的数目超过m,那么这一半的区域里一定有重复的数字
 * 否则，另一半m+1~n的区间里一定包含重复的数字。继续把包含重复数字的区间一分为二，直到找出一个重复的数字
 *
 * 时间复杂度为o(nlogn), 空间复杂度为o(1)
 *
 *
 * @param numbers
 * @param length
 * @param duplicate
 * @return
 */
bool duplicate2(const int *numbers, int length, int *duplicate);
int countRange(const int *numbers, int length, int start, int end);

#endif //INTERVIEW_SOURCE_H
