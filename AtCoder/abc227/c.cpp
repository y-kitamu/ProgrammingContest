/*
 * c.cpp
 *
 * Create Date : 2021-11-13 21:09:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int ans = 0;
    long long int max_a = std::pow(N, 1.0 / 3.0) + 1.0;
    for (int a = 1; a <= max_a; a++) {
        long long int max_b = std::sqrt(N / a) + 1.0;
        for (int b = a; b <= max_b; b++) {
            long long int max_c = N / (a * b);
            if (max_c >= b) {
                ans += max_c - b + 1;
            }
        }
    }
    std::cout << ans << std::endl;
}
