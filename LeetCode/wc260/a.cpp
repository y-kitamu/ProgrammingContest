/*
 * a.cpp
 *
 * Create Date : 2021-09-26 11:28:42
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumDifference(std::vector<int>& nums) {
        int max = -1e9;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                max = std::max(nums[j] - nums[i], max);
            }
        }
        if (max <= 0) {
            max = -1;
        }

        return max;
    }
};

int main() {}
