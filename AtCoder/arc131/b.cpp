/*
 * b.cpp
 *
 * Create Date : 2021-12-05 21:06:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> c(H, std::vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> c[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (c[i][j] != '.') {
                continue;
            }
            std::vector<int> mark(5, 0);
            if (i > 0) {
                if (c[i - 1][j] != '.') {
                    mark[c[i - 1][j] - '1'] = 1;
                }
            }
            if (j > 0) {
                if (c[i][j - 1] != '.') {
                    mark[c[i][j - 1] - '1'] = 1;
                }
            }
            if (i < H - 1) {
                if (c[i + 1][j] != '.') {
                    mark[c[i + 1][j] - '1'] = 1;
                }
            }
            if (j < W - 1) {
                if (c[i][j + 1] != '.') {
                    mark[c[i][j + 1] - '1'] = 1;
                }
            }

            for (int k = 0; k < 5; k++) {
                if (mark[k] == 0) {
                    c[i][j] = '1' + k;
                    break;
                }
            }
        }
    }

    for (auto& row : c) {
        for (auto& val : row) {
            std::cout << (char)val;
        }
        std::cout << std::endl;
    }
}
