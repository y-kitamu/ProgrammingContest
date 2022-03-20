/*
 * c.cpp
 *
 * Create Date : 2022-03-20 11:49:21
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> maximumBobPoints(int numArrows, std::vector<int>& aliceArrows) {
        std::vector<std::vector<int>> dp(12, std::vector<int>(numArrows + 1, 0));

        for (int i = 1; i < 12; i++) {
            int val = aliceArrows[i] + 1;
            for (int j = 1; j <= numArrows; j++) {
                if (j < val) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - val] + i);
                }
            }
            for (auto& val : dp[i]) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        int idx = numArrows;
        std::vector<int> ans(12, 0);
        for (int i = 11; i > 0; i--) {
            if (dp[i][idx] == dp[i - 1][idx]) {
                continue;
            }
            int j = idx - aliceArrows[i] - 1;
            for (; j >= 0; j--) {
                if (dp[i][idx] - dp[i - 1][j] == i) {
                    break;
                }
            }
            ans[i] = idx - j;
            idx = j;
        }
        ans[0] = idx;
        return ans;
    }
};


int main() {}
