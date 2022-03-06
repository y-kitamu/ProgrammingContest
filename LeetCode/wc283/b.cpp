/*
 * b.cpp
 *
 * Create Date : 2022-03-06 11:35:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long minimalKSum(std::vector<int>& nums, int k) {
        std::set<int> set(nums.begin(), nums.end());
        long long int sum = (long long int)(k + 1) * (long long int)k / 2ll;
        auto res = set.begin();
        auto cur = set.lower_bound(k);
        while (res != cur || (cur != set.end() && k == *cur)) {
            sum -= *res;
            sum += ++k;
            cur = set.lower_bound(k);
            res++;
        }
        return sum;
    }
};


int main() {}
