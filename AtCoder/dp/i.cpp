/*
 * i.cpp
 *
 * Create Date : 2021-08-25 20:19:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<double> ps(N);
    for (int i = 0; i < N; i++) {
        std::cin >> ps[i];
    }

    std::vector<double> cur(N + 1, 0.0);
    cur[0] = 1.0;
    for (int i = 0; i < N; i++) {
        std::vector<double> next(N + 1, 0.0);
        for (int j = N; j >= 0; j--) {
            next[j + 1] += cur[j] * ps[i];
            next[j] += cur[j] * (1 - ps[i]);
        }
        cur = next;
    }
    // for (auto& val : cur) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;

    double sum = 0.0;
    for (int i = N / 2 + 1; i <= N; i++) {
        sum += cur[i];
    }
    std::cout << std::fixed << std::setprecision(10) << sum << std::endl;
}
