/*
 * a.cpp
 *
 * Create Date : 2021-08-22 11:29:57
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int findGCD(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return gcd(nums[0], nums[nums.size() - 1]);
    }

    int gcd(int lhs, int rhs) {
        while (rhs > 0) {
            auto tmp = rhs;
            rhs = lhs % rhs;
            lhs = tmp;
        }
        return lhs;
    }
};


int main() {}
