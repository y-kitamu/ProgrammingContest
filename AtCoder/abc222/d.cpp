/*
 * d.cpp
 *
 * Create Date : 2021-10-09 21:19:27
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int MOD = 998244353;
    int N;
    std::cin >> N;

    std::vector<int> a(N), b(N);

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    std::vector<long long int> cur(b[N - 1] + 1, 0);
    for (int i = 0; i <= b[N - 1]; i++) {
        if (a[0] <= i && i <= b[0]) {
            cur[i] = 1;
        }
        if (i > 0) {
            cur[i] += cur[i - 1];
        }
        // std::cout << cur[i] << " ";
    }
    // std::cout << std::endl;

    for (int i = 1; i < N; i++) {
        std::vector<long long int> next(b[N - 1] + 1, 0);
        for (int j = 0; j <= b[N - 1]; j++) {
            if (a[i] <= j && j <= b[i]) {
                next[j] = cur[j];
            }
            if (j > 0) {
                next[j] = (next[j] + next[j - 1]) % MOD;
            }
            // std::cout << next[j] << " ";
        }
        // std::cout << std::endl;
        cur = next;
    }
    std::cout << cur[b[N - 1]] << std::endl;
}
