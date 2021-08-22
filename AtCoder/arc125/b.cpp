/*
 * b.cpp
 *
 * Create Date : 2021-08-22 21:09:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int MOD = 998244353;
    long long int N;
    std::cin >> N;

    long long int cnt = 0;
    long long int x = 1;
    for (; x * x <= N; x++) {
        cnt = (cnt + x) % MOD;
    }

    long long int k = x;
    for (; k > 0; k--) {
        long long int new_x = (N + k * k) / (2 * k);
        // std::cout << "k = " << k << ", new_x = " << new_x << std::endl;
        if (new_x - x > 0) {
            cnt = (cnt + (new_x - x) * k % MOD) % MOD;
        }
        x = new_x;
    }

    std::cout << cnt << std::endl;
}
