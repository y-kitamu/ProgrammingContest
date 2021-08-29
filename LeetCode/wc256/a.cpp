/*
 * a.cpp
 *
 * Create Date : 2021-08-29 11:28:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minimumDifference(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int min = nums[k - 1] - nums[0];
        for (int i = 0; i <= nums.size() - k; i++) {
            min = std::min(min, nums[i + k - 1] - nums[i]);
        }
        return min;
    }
};


int main() {}
