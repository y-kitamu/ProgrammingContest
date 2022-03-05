/*
 * c.cpp
 *
 * Create Date : 2022-03-05 21:07:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int MOD = 998244353;
    int N;
    std::cin >> N;

    std::vector<long long int> dp(9, 1);

    for (int i = 0; i < N - 1; i++) {
        std::vector<long long int> next(9, 0);
        for (int j = 0; j < 9; j++) {
            next[j] = dp[j];
            if (j > 0) {
                next[j] = (next[j] + dp[j - 1]) % MOD;
            }
            if (j < 8) {
                next[j] = (next[j] + dp[j + 1]) % MOD;
            }
        }
        dp = next;
    }
    long long int ans = 0;
    for (auto& val : dp) {
        ans += val;
    }
    std::cout << ans % MOD << std::endl;
}
