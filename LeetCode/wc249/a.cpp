/*
 * a.cpp
 *
 * Create Date : 2021-07-11 11:27:27
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        std::vector<int> ans(nums.size() * 2);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }
        return ans;
    }
};


int main() {}
