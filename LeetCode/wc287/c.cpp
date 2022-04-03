/*
 * c.cpp
 *
 * Create Date : 2022-04-03 11:43:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumCandies(std::vector<int>& candies, long long k) {
        long long max = 1e12;
        long long min = 0;

        while (min != max) {
            long long mid = (min + max + 1) / 2;

            long long cnt = 0;
            for (auto& cand : candies) {
                cnt += cand / mid;
            }

            if (cnt < k) {
                max = mid - 1;
            } else {
                min = mid;
            }
        }
        return min;
    }
};


int main() {}
