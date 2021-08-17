/*
 * 004.cpp
 *
 * Create Date : 2021-08-17 19:57:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> grid(H, std::vector<int>(W));
    std::vector<int> rows(H, 0), cols(W, 0);
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> grid[y][x];
            rows[y] += grid[y][x];
            cols[x] += grid[y][x];
        }
    }

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cout << rows[y] + cols[x] - grid[y][x];
            if (x < W - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
