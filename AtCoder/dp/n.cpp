/*
 * n.cpp
 *
 * Create Date : 2021-09-13 21:00:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

long long int solve(int left, int right, std::vector<std::vector<long long int>>& cost,
                    std::vector<long long int>& sums) {
    if (cost[left][right] >= 0) {
        return cost[left][right];
    }

    long long int min = 1e18;
    for (int i = left; i < right; i++) {
        min = std::min(min, solve(left, i, cost, sums) + solve(i + 1, right, cost, sums));
    }
    cost[left][right] = sums[right + 1] - sums[left] + min;
    return cost[left][right];
}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<long long int>> cost(N, std::vector<long long int>(N, -1));
    std::vector<long long int> sums(N + 1, 0);
    for (int i = 0; i < N; i++) {
        sums[i + 1] = sums[i] + a[i];
    }
    for (int i = 0; i < N; i++) {
        cost[i][i] = 0;
    }
    std::cout << solve(0, N - 1, cost, sums) << std::endl;
}
