/*
 * f.cpp
 *
 * Create Date : 2021-11-27 21:48:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    std::vector<long long int> dp(2, 0);
    // Nが0と逆
    dp[0] = B[N - 1];  // 0と逆側
    dp[1] = A[0];      // 0と同じ側
    for (int i = 1; i < N - 1; i++) {
        std::vector<long long int> next(2, 0);
        next[0] = std::min(dp[0] + B[i - 1], dp[1]);
        next[1] = std::min(dp[1] + B[i - 1] + A[i], dp[0] + A[i]);
        dp = next;
    }
    long long int ans1 = std::min(dp[0] + B[N - 2], dp[1]);

    // Nと0が同じ
    dp[0] = 0;
    dp[1] = A[0] + B[N - 1];
    for (int i = 1; i < N - 1; i++) {
        std::vector<long long int> next(2, 0);
        next[0] = std::min(dp[0] + B[i - 1], dp[1]);
        next[1] = std::min(dp[1] + B[i - 1] + A[i], dp[0] + A[i]);
        dp = next;
    }
    long long int ans2 = std::min(dp[0] + A[N - 1], dp[1] + A[N - 1] + B[N - 2]);

    std::cout << std::min(ans1, ans2) << std::endl;
}
