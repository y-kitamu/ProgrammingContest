/*
 * m.cpp
 *
 * Create Date : 2021-09-01 06:38:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


using ll = long long int;


int main() {
    ll N, K;
    std::cin >> N >> K;

    std::vector<ll> a(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    if (K == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (sum < K) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(K + 1, 0));

    for (int i = 0; i <= K; i++) {
        dp[0][i] = 1;
    }
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    ll mod = 1e9 + 7;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            if (a[i - 1] < j) {
                dp[i][j] -= dp[i - 1][j - a[i - 1] - 1];
            }
            dp[i][j] %= mod;
            // std::cout << dp[i][j] << " ";
        }
        // std::cout << std::endl;
    }

    std::cout << ((dp[N][K] - dp[N][std::max(0ll, K - 1)]) % mod + mod) % mod << std::endl;
}
