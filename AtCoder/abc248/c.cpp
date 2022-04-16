/*
 * c.cpp
 *
 * Create Date : 2022-04-16 21:04:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int MOD = 998244353;
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<long long int> dp(K + 1, 0);
    dp[0] = 1;

    for (int n = 0; n < N; n++) {
        std::vector<long long int> next(K + 1, 0);

        for (int k = 0; k <= K; k++) {
            for (int m = 1; m <= M; m++) {
                if (k + m >= K + 1) {
                    break;
                }
                next[k + m] = (next[k + m] + dp[k]) % MOD;
            }
        }
        // for (auto& val : next) {
        //     std::cout << val << " ";
        // }
        dp = next;
    }

    long long int ans = 0;
    for (auto& val : dp) {
        ans += val;
    }

    std::cout << ans % MOD << std::endl;
}
