/*
 * j.cpp
 *
 * Create Date : 2021-08-25 20:50:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


double solve(int i, int j, int k, int N, std::vector<std::vector<std::vector<double>>>& dp) {
    if (i == 0 && j == 0 && k == 0) {
        dp[i][j][k] = 0.0;
        return 0.0;
    }
    if (dp[i][j][k] >= 0.0) {
        return dp[i][j][k];
    }

    dp[i][j][k] = (double)N / (i + j + k);
    double ijk = i + j + k;
    if (i > 0) {
        dp[i][j][k] += solve(i - 1, j + 1, k, N, dp) * i * 1.0 / ijk;
    }
    if (j > 0) {
        dp[i][j][k] += solve(i, j - 1, k + 1, N, dp) * j * 1.0 / ijk;
    }
    if (k > 0) {
        dp[i][j][k] += solve(i, j, k - 1, N, dp) * k * 1.0 / ijk;
    }
    return dp[i][j][k];
}


int main() {
    int N;
    std::cin >> N;
    std::vector<int> cnts(3, 0);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        cnts[a - 1]++;
    }

    std::vector<std::vector<std::vector<double>>> dp(
        N + 1, std::vector<std::vector<double>>(N + 1, std::vector<double>(N + 1, -1.0)));

    double ans = solve(cnts[2], cnts[1], cnts[0], N, dp);
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
}
