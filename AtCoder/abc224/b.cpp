/*
 * b.cpp
 *
 * Create Date : 2021-10-23 21:01:43
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> A(H, std::vector<int>(W));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> A[y][x];
        }
    }

    for (int i1 = 0; i1 < H; i1++) {
        for (int i2 = i1; i2 < H; i2++) {
            for (int j1 = 0; j1 < W; j1++) {
                for (int j2 = j1; j2 < W; j2++) {
                    if (A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]) {
                        std::cout << "No" << std::endl;
                        return 0;
                    }
                }
            }
        }
    }
    std::cout << "Yes" << std::endl;
}
