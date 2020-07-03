//
// Created by Chen Shuquan on 2020/5/13.
//

#include "maxInWindow.h"

#include <deque>

vector<int> maxInWindow(vector<int> data, int wSize) {
    vector<int> maxVal;
    deque<int> valDeque;
    int dLen = data.size();
    if (dLen > wSize && wSize > 0) {
        for (int i = 0; i < wSize; i++) {
            while (!valDeque.empty() && data[i] > data[valDeque.back()]) {
                valDeque.pop_back();
            }
            valDeque.push_back(i);
        }

        for (int i = wSize; i < data.size(); i++) {
            maxVal.push_back(data[valDeque.front()]);
            while (!valDeque.empty() && data[i] > data[valDeque.back()]) {
                valDeque.pop_back();
            }
            while (!valDeque.empty() && (i - valDeque.front()) >= wSize)
                valDeque.pop_front();
            valDeque.push_back(i);
        }
        maxVal.push_back(data[valDeque.front()]);
    }
    return maxVal;
}