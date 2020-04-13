/*
 * sumofgcd.cpp
 *
 * Create Date : 2020-04-12 21:13:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>
#include <numeric>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> gcd(N + 1, std::vector<int>(N + 1, -1));
    int sum = 0;
    
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            for (int k = j; k <= N; k++) {
                if (gcd[i][j] == -1) {
                    gcd[i][j] = std::gcd(i, j);
                }
                int g_ij = gcd[i][j];
                if (gcd[g_ij][k] == -1) {
                    gcd[g_ij][k] = std::gcd(g_ij, k);
                }
                int g_ijk = gcd[g_ij][k];
                if (i == k) {
                    sum += g_ijk;
                } else if (i == j || j == k) {
                    sum += g_ijk * 3;
                } else {
                    sum += g_ijk * 6;
                }
            }
        }
    }
    std::cout << sum << std::endl;
}
