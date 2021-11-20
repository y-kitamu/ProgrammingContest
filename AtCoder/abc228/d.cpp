/*
 * d.cpp
 *
 * Create Date : 2021-11-20 21:15:57
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int Q;
    std::cin >> Q;
    long long int N = 1 << 20;

    std::vector<long long int> A(N, -1);
    std::vector<long long int> next(N);
    std::iota(next.begin(), next.end(), 1);
    next[N - 1] = 0;

    for (int i = 0; i < Q; i++) {
        long long int t, x;
        std::cin >> t >> x;

        if (t == 1) {
            std::vector<long long int> updates;
            long long int idx = x % N;
            while (A[idx] != -1) {
                updates.emplace_back(idx);
                idx = next[idx];
            }
            for (auto& i : updates) {
                next[i] = next[idx];
            }
            A[idx] = x;
        } else {
            std::cout << A[x % N] << std::endl;
        }
    }
}
