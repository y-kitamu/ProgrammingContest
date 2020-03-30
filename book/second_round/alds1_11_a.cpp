/*
 * alds1_11_a.cpp
 *
 * Create Date : 2020-03-30 23:17:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <cstring>
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int ad_mat[n][n];
    memset(ad_mat, 0, sizeof(int) * n * n);

    int u, v, k;
    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            ad_mat[u - 1][v - 1] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            std::cout << ad_mat[i][j] << " ";
        }
        std::cout << ad_mat[i][n - 1] << std::endl;
    }
}
