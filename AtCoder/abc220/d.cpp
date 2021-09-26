/*
 * d.cpp
 *
 * Create Date : 2021-09-26 21:10:46
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long int mod = 998244353;
    std::vector<long long int> prev(10, 0);
    prev[A[0]] = 1;
    for (int i = 1; i < N; i++) {
        std::vector<long long int> cur(10, 0);
        for (int j = 0; j < 10; j++) {
            int f = j * A[i] % 10;
            int g = (j + A[i]) % 10;
            cur[f] = (cur[f] + prev[j]) % mod;
            cur[g] = (cur[g] + prev[j]) % mod;
        }
        prev = cur;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << prev[i] << std::endl;
    }
}
