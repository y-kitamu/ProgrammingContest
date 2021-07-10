/*
 * c.cpp
 *
 * Create Date : 2021-07-10 21:03:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> C(N);
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::sort(C.begin(), C.end());

    long long int MOD = 1e9 + 7;
    long long int sum = C[0];
    for (int i = 1; i < N; i++) {
        sum = (C[i] - i) * sum % MOD;
    }
    std::cout << sum << std::endl;
}
