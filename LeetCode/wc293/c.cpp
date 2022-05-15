/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-15 11:43:03
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int largestCombination(std::vector<int>& candidates) {
        int max = 0;
        for (int i = 0; i < 30; i++) {
            int cnt = 0;
            for (auto& val : candidates) {
                if (val & (1 << i)) {
                    cnt++;
                }
            }
            max = std::max(cnt, max);
        }
        return max;
    }
};

int main() {}
