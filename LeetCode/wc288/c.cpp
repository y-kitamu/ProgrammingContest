/*
 * c.cpp
 *
 * Create Date : 2022-04-10 12:00:24
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumProduct(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());

        int idx = 1;
        while (k > 0) {
            while (idx < nums.size() && nums[0] == nums[idx]) {
                idx++;
            }
            for (int i = 0; i < idx; i++) {
                nums[i]++;
                k--;
                if (k == 0) {
                    break;
                }
            }
        }

        long long int mod = 1e9 + 7;
        long long int ans = 1;
        for (auto& val : nums) {
            ans = (ans * val) % mod;
        }
        return ans;
    }
};


int main() {}
