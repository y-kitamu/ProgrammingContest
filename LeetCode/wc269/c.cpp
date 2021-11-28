/*
 * c.cpp
 *
 * Create Date : 2021-11-28 11:40:46
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minimumDeletions(std::vector<int>& nums) {
        int min_idx = 0, max_idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[max_idx] < nums[i]) {
                max_idx = i;
            }
        }
        int n = nums.size();
        if (min_idx > max_idx) {
            std::swap(min_idx, max_idx);
        }
        int ans = std::min(max_idx + 1, n - min_idx);
        ans = std::min(ans, min_idx + 1 + n - max_idx);
        return ans;
    }
};


int main() {}
