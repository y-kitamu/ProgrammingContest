/*
 * c.cpp
 *
 * Create Date : 2021-09-26 21:06:10
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;
    std::vector<long long int> sums(N + 1, 0);

    for (int i = 0; i < N; i++) {
        long long int a;
        std::cin >> a;
        sums[i + 1] = sums[i] + a;
    }
    long long int X;
    std::cin >> X;
    long long int loop = X / sums[N];
    long long int res = X % sums[N];
    auto dist = std::distance(sums.begin(), std::upper_bound(sums.begin(), sums.end(), res));
    std::cout << loop * N + dist << std::endl;
}
