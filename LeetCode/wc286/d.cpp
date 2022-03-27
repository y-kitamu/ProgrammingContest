/*
 * d.cpp
 *
 * Create Date : 2022-03-27 12:18:05
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maxValueOfCoins(std::vector<std::vector<int>>& piles, int k) {
        std::vector<int> dp(k + 1, 0);
        for (int i = 0; i < piles.size(); i++) {
            std::vector<int> next(k + 1, 0);
            for (int l = 1; l <= k; l++) {
                int sum = 0;
                next[l] = dp[l];
                for (int j = 0; j < std::min((int)piles[i].size(), l); j++) {
                    sum += piles[i][j];
                    next[l] = std::max(next[l], dp[l - j - 1] + sum);
                }
            }
            dp = next;
        }
        return dp[k];
    }
};


int main() {}
