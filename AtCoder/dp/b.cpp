/*
 * b.cop
 *
 * Create Date : 2021-08-23 21:35:52
 * Copyright (c) 2019- Yusuke Tamra <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> h(N);
    for (int i = 0; i < N; i++) {
        std::cin >> h[i];
    }

    std::vector<int> cost(N, 2e9);
    cost[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < std::min(N, i + K + 1); j++) {
            cost[j] = std::min(cost[j], cost[i] + std::abs(h[j] - h[i]));
        }
    }
    std::cout << cost[N - 1] << std::endl;
}
