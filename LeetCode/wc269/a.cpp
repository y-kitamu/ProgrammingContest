/*
 * a.cpp
 *
 * Create Date : 2021-11-28 11:24:56
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        auto itr = std::lower_bound(nums.begin(), nums.end(), target);
        int idx = std::distance(nums.begin(), itr);
        std::vector<int> ans;
        while (itr != nums.end() && *itr == target) {
            ans.emplace_back(idx);
            idx++;
            itr++;
        }
        return ans;
    }
};

int main() {}
