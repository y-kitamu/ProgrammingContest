/*
 * b.cpp
 *
 * Create Date : 2021-08-15 11:36:34
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> rearrangeArray(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 2) {
            std::swap(nums[i], nums[i + 1]);
        }
        return nums;
    }
};


int main() {}
