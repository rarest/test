//
// Created by ChenShuQuan on 2021/12/1.
//

#include "common.h"
#include <vector>
#include <unordered_map>

std::vector<int> findFrequentNumbers(const std::vector<int> nums, int k) {
    std::unordered_map<int, int> buckets;
    int maxCount = 0;
    for (const int &val: nums) {
        maxCount = std::max(maxCount, ++buckets[val]);
    }
    vector<vector<int> > frequentArray(maxCount + 1);
    for (const auto &bucket: buckets) {
        frequentArray[bucket.second].push_back(bucket.first);
    }
    int j = 0;
    std::vector<int> ret;
    for (size_t i = frequentArray.size() - 1; i >= 0 && j < k; i--) {
        for (const int &val: frequentArray[i]) {
            if (j < k) {
                ret.push_back(val);
                ++j;
            } else
                break;
        }
    }
    return ret;
}

int main(void) {
    std::vector<int> a = {-1,-1};
    std::vector<int> ret = findFrequentNumbers(a, 1);
}
