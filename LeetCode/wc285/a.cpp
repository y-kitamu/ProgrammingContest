/*
 * a.cpp
 *
 * Create Date : 2022-03-20 11:28:51
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int countHillValley(std::vector<int>& nums) {
        std::vector<int> compressed;
        compressed.emplace_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                compressed.emplace_back(nums[i]);
            }
        }
        int cnt = 0;
        for (int i = 1; i < compressed.size() - 1; i++) {
            if (compressed[i] > compressed[i - 1] && compressed[i] > compressed[i + 1]) {
                cnt++;
            }
            if (compressed[i] < compressed[i - 1] && compressed[i] < compressed[i + 1]) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {}
