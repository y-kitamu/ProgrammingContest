/*
 * d.cpp
 *
 * Create Date : 2022-02-13 12:11:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumANDSum(std::vector<int>& nums, int numSlots) {
        std::vector<int> dp(1 << (numSlots * 2), -1);

        for (int i = 0; i < numSlots; i++) {
            dp[1 << (i * 2)] = (i + 1) & nums[0];
        }

        for (int k = 1; k < nums.size(); k++) {
            std::vector<int> next(1 << (numSlots * 2), -1);
            for (int i = 0; i < (1 << (numSlots * 2)); i++) {
                if (dp[i] == -1) {
                    continue;
                };
                for (int j = 0; j < numSlots * 2; j++) {
                    if (i & (1 << j)) {
                        continue;
                    }
                    next[i | (1 << j)] =
                        std::max(next[i | (1 << j)], dp[i] + int(nums[k] & (j / 2 + 1)));
                }
            }
            dp = next;
        }
        auto max = dp[0];
        for (auto& val : dp) {
            max = std::max(val, max);
        }
        return max;
    }
};


int main() {}
