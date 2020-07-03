//
// Created by Chen Shuquan on 2020/5/13.
//

#ifndef INTERVIEW_MAXINWINDOW_H
#define INTERVIEW_MAXINWINDOW_H

#include "common.h"
#include <vector>

/**
 *  [2,3,4,2,6,2,5,1] + (window size 3) -> [4,4,6,6,6,5]  复杂度为O(n)
 * @param data  data array
 * @param n window size
 * @return
 */
vector<int> maxInWindow(vector<int> data, int wSize);




#endif //INTERVIEW_MAXINWINDOW_H
