/*
 * c.cpp
 *
 * Create Date : 2021-09-11 21:03:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


std::vector<std::vector<char>> rotate90(std::vector<std::vector<char>>& src) {
    int N = src.size();
    std::vector<std::vector<char>> dst(N, std::vector<char>(N));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            dst[y][x] = src[N - x - 1][y];
        }
    }
    return dst;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<char>> S(N, std::vector<char>(N)), T(N, std::vector<char>(N));

    int cnt_s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> S[i][j];
            if (S[i][j] == '#') {
                cnt_s++;
            }
        }
    }
    int cnt_t = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> T[i][j];
            if (T[i][j] == '#') {
                cnt_t++;
            }
        }
    }
    if (cnt_s != cnt_t) {
        std::cout << "No" << std::endl;
        return 0;
    }

    auto search_min = [&N](auto& vec) {
        std::vector<int> minmax(4);
        minmax[0] = N;
        minmax[1] = N;
        minmax[2] = 0;
        minmax[3] = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (vec[y][x] == '#') {
                    minmax[0] = std::min(minmax[0], x);
                    minmax[1] = std::min(minmax[1], y);
                    minmax[2] = std::max(minmax[2], x);
                    minmax[3] = std::max(minmax[3], y);
                }
            }
        }
        return minmax;
    };

    auto mm_s = search_min(S);
    for (int i = 0; i < 4; i++) {
        auto mm_t = search_min(T);
        int dx = mm_t[0] - mm_s[0];
        int dy = mm_t[1] - mm_s[1];

        bool flag = true;
        for (int y = mm_s[1]; y <= mm_s[3]; y++) {
            for (int x = mm_s[0]; x <= mm_s[2]; x++) {
                if (x + dx >= N || y + dy >= N || x + dx < 0 || y + dy < 0) {
                    flag = false;
                    break;
                }
                flag &= S[y][x] == T[y + dy][x + dx];
            }
        }

        if (flag) {
            std::cout << "Yes" << std::endl;
            return 0;
        }

        T = rotate90(T);
    }

    std::cout << "No" << std::endl;
}
