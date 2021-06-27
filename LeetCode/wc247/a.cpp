/*
 * a.cpp
 *
 * Create Date : 2021-06-27 11:27:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int maxProductDifference(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};


int main() {}
