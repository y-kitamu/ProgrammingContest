/*
 * a.cpp
 *
 * Create Date : 2022-03-13 11:29:25
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int min = std::max(i - k, 0);
            int max = std::min(i + k + 1, int(nums.size()));
            for (int j = min; j < max; j++) {
                if (nums[j] == key) {
                    ans.emplace_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main() {}
