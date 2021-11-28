/*
 * b.cpp
 *
 * Create Date : 2021-11-28 11:35:00
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> getAverages(std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> ans(nums.size(), -1);
        long long int sum = 0;
        for (int i = 0; i < std::min(k * 2 + 1, n); i++) {
            sum += nums[i];
        }

        for (int i = k; i < n - k; i++) {
            ans[i] = sum / (2 * k + 1);
            if (i + k + 1 < n) {
                sum += nums[i + k + 1] - nums[i - k];
            }
        }
        return ans;
    }
};

int main() {}
