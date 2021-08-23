/*
 * a.cpp
 *
 * Create Date : 2021-08-23 20:35:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> h(N);
    for (int i = 0; i < N; i++) {
        std::cin >> h[i];
    }

    std::vector<int> cost(N, 2e9);
    cost[0] = 0;
    for (int i = 0; i < N; i++) {
        if (i + 1 < N) {
            cost[i + 1] = std::min(std::abs(h[i + 1] - h[i]) + cost[i], cost[i + 1]);
        }
        if (i + 2 < N) {
            cost[i + 2] = std::min(std::abs(h[i + 2] - h[i]) + cost[i], cost[i + 2]);
        }
    }
    std::cout << cost[N - 1] << std::endl;
}
