/*
 * h.cpp
 *
 * Create Date : 2021-08-25 20:11:21
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int MOD = 1e9 + 7;
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> map(H, std::vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> map[i][j];
        }
    }

    std::vector<std::vector<long long int>> dp(H, std::vector<long long int>(W, 0));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < H - 1 && map[i + 1][j] == '.') {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }
            if (j < W - 1 && map[i][j + 1] == '.') {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }
    std::cout << dp[H - 1][W - 1] << std::endl;
}
