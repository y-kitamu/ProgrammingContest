/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-26 11:34:53
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int countHousePlacements(int n) {
        long long int mod = 1e9 + 7;
        long long int ans = 0;
        std::vector<long long int> dp(2, 1);

        for (int i = 1; i < n; i++) {
            std::vector<long long int> next(2, 0);
            next[0] = (dp[0] + dp[1]) % mod;
            next[1] = (dp[0]) % mod;
            dp = next;
        }
        ans = (dp[0] + dp[1]) % mod;
        return (ans * ans) % mod;
    }
};

int main() {}
