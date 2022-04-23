/*
 * e.cpp
 *
 * Create Date : 2022-04-23 21:40:12
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

int main() {
    long long int N, P;
    std::cin >> N >> P;

    std::vector<std::vector<long long int>> dp(N, std::vector<long long int>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i < N; i++) {
        long long int pow = 25;
        if (i == 0) {
            pow = 26;
        }

        for (int j = 1; j <= N; j++) {
            for (int k = 2; k <= 5; k++) {
                long long int max = std::max(0, j - (int)std::pow(10, k - 2));
                long long int min = std::max(0, j - (int)std::pow(10, k - 1) + 1);
                dp[i][j] += dp[i - k][max] - dp[i - k][min];
            }
        }
    }
}
