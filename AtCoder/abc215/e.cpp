/*
 * e.cpp
 *
 * Create Date : 2021-08-21 21:51:37
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


using ll = long long int;

int main() {
    ll MOD = 998244353;
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<int> vals(N);
    for (int i = 0; i < N; i++) {
        vals[i] = S[i] - 'A';
    }

    std::vector<std::vector<ll>> dp(N + 1, std::vector<ll>(1 << 10, 0));
    std::vector<ll> pow(10, 0);
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1 << vals[0]] = 1;
    pow[vals[0]] = 1;

    for (int i = 2; i <= N; i++) {
        int c = 1 << vals[i - 1];
        for (int j = 0; j < (1 << 10); j++) {
            dp[i][j] = dp[i - 1][j];
            if (j & c && dp[i][j - c] > 0) {
                dp[i][j] += dp[i][j - c];
                dp[i][j] += pow[vals[i - 1]];
                pow[vals[i - 1]] = (pow[vals[i - 1]] + dp[i][j - c]) % MOD;
            }
        }

        ll sum = 0;
        for (int j = 1; j < (1 << 10); j++) {
            sum = (sum + dp[i][j]) % MOD;
        }
        std::cout << sum << " ";
    }
    std::cout << std::endl;

    ll sum = 0;
    for (int i = 1; i < (1 << 10); i++) {
        sum = (sum + dp[N][i]) % MOD;
    }

    std::cout << sum << std::endl;
}
