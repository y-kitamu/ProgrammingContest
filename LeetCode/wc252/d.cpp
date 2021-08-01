/*
 * d.cpp
 *
 * Create Date : 2021-08-01 12:01:59
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int countSpecialSubsequences(std::vector<int>& nums) {
        long long int MOD = 1e9 + 7;
        std::vector<long long int> cnts(3, 0);
        int idx = 0;
        while (idx < nums.size() && nums[idx] != 0) {
            idx++;
        }
        cnts[0] = 1;
        idx++;

        for (; idx < nums.size(); idx++) {
            if (nums[idx] == 0) {
                cnts[0] = (cnts[0] * 2ll + 1ll) % MOD;
            } else if (nums[idx] == 1) {
                cnts[1] = (cnts[1] * 2ll + cnts[0]) % MOD;
            } else if (nums[idx] == 2) {
                cnts[2] = (cnts[2] * 2ll + cnts[1]) % MOD;
            }
        }
        return cnts[2];
    }
};

int main() {}
