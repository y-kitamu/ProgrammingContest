/*
 * b.cpp
 *
 * Create Date : 2021-06-06 11:36:14
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int reductionOperations(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                sum += nums.size() - i;
            }
        }
        return sum;
    }
};


int main() {}
