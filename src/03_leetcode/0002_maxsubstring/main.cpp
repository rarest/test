//
// Created by ChenShuQuan on 2021/11/26.
//


#include "common.h"
#include <unordered_set>

int search_max_sub_string(std::string str) {
    int n = str.size();
    std::unordered_set<char> subStr;
    int subStrEnd = -1;
    int maxSubStrLen = 0;
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            subStr.erase(str[i - 1]);
        while (subStrEnd + 1 < n && !subStr.count(str[subStrEnd + 1])) {
            subStr.insert(str[subStrEnd + 1]);
            ++subStrEnd;
        }
        maxSubStrLen = std::max(maxSubStrLen, subStrEnd - i + 1);

    }
    return maxSubStrLen;
}




int main() {
    int ret = search_max_sub_string("abcabcbb");
    return 0;
}
