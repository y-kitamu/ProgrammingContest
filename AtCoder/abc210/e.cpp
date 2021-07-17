/*
 * e.cpp
 *
 * Create Date : 2021-07-17 22:15:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long int GCD(long long int a, long long int b) {
    while (b != 0) {
        long long int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


int main() {
    long long int N, M;
    std::cin >> N >> M;

    long long int gcd = N;
    std::vector<std::vector<long long int>> AC(M, std::vector<long long int>(2));

    std::map<int, long long int> cost;
    for (int i = 0; i < M; i++) {
        std::cin >> AC[i][0] >> AC[i][1];
        gcd = GCD(gcd, AC[i][0]);
        long long int g = GCD(AC[i][0], N);
        if (cost.find(g) == cost.end()) {
            cost[g] = AC[i][1];
        } else {
            cost[g] = std::min(cost[g], AC[i][1]);
        }
    }

    if (gcd > 1) {
        std::cout << -1 << std::endl;
        return 0;
    }

    long long int min = 1e18;
    for (auto& p0 : cost) {
        for (auto& p1 : cost) {
            if (p0.first == p1.first) {
                continue;
            }
            if (GCD(p0.first, p1.first) == 1) {
                // std::cout << p0.first << ", " << p0.second << " : " << p1.first << " , " << p1.second
                //           << std::endl;
                long long int val = std::min((p0.first - 1) * p1.second + p0.second * (N - p0.first),
                                             (p1.first - 1) * p0.second + p1.second * (N - p1.first));
                min = std::min(val, min);
            }
        }
    }
    std::cout << min << std::endl;
}
