/*
 * d.cpp
 *
 * Create Date : 2021-09-18 21:22:17
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, X, Y;
    std::cin >> N >> X >> Y;


    std::vector<int> as(N), bs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> as[i] >> bs[i];
    }

    std::vector<std::vector<int>> dp(Y + 1, std::vector<int>(X + 1, 1e9));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        int a = as[i], b = bs[i];
        for (int y = Y; y >= 0; y--) {
            int dy = std::min(y + b, Y);
            for (int x = X; x >= 0; x--) {
                int dx = std::min(x + a, X);
                dp[dy][dx] = std::min(dp[dy][dx], dp[y][x] + 1);
            }
        }
    }

    if (dp[Y][X] == 1e9) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[Y][X] << std::endl;
    }
}
