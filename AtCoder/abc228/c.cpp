/*
 * c.cpp
 *
 * Create Date : 2021-11-20 21:06:28
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> P(N, 0);

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < 3; i++) {
            int p;
            std::cin >> p;
            P[j] += p;
        }
    }

    std::vector<int> sp = P;
    std::sort(sp.begin(), sp.end(), std::greater<>());

    for (int i = 0; i < N; i++) {
        auto ptr = std::lower_bound(sp.begin(), sp.end(), P[i] + 300, std::greater<>());
        int dist = std::distance(sp.begin(), ptr);
        if (dist < K) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
