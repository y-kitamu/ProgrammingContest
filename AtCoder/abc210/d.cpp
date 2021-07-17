/*
 * d.cpp
 *
 * Create Date : 2021-07-17 21:13:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int H, W, C;
    std::cin >> H >> W >> C;

    std::vector<std::vector<long long int>> A(H, std::vector<long long int>(W));

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> A[y][x];
        }
    }

    std::vector<long long int> dp(W, 1e18), prev(W);

    long long int min = 1e18;
    prev[0] = A[0][0];
    for (int i = 1; i < W; i++) {
        min = std::min(prev[i - 1] + C + A[0][i], min);
        prev[i] = std::min(A[0][i], prev[i - 1] + C);
    }
    for (int y = 1; y < H; y++) {
        min = std::min(min, prev[0] + C + A[y][0]);
        dp[0] = std::min(prev[0] + C, A[y][0]);
        for (int x = 1; x < W; x++) {
            min = std::min(min, std::min(dp[x - 1], prev[x]) + A[y][x] + C);
            dp[x] = std::min(A[y][x], std::min(dp[x - 1], prev[x]) + C);
        }
        prev = dp;
    }

    prev[W - 1] = A[0][W - 1];
    for (int i = W - 2; i >= 0; i--) {
        min = std::min(min, prev[i + 1] + C + A[0][i]);
        prev[i] = std::min(A[0][i], prev[i + 1] + C);
    }
    for (int y = 1; y < H; y++) {
        min = std::min(min, prev[W - 1] + C + A[y][W - 1]);
        dp[W - 1] = std::min(prev[W - 1] + C, A[y][W - 1]);
        for (int x = W - 2; x >= 0; x--) {
            min = std::min(min, std::min(dp[x + 1], prev[x]) + A[y][x] + C);
            dp[x] = std::min(A[y][x], std::min(dp[x + 1], prev[x]) + C);
        }
        prev = dp;
    }

    std::cout << min << std::endl;
}
