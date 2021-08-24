/*
 * e.cpp
 *
 * Create Date : 2021-08-24 20:42:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<long long int> w(N), v(N);
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> w[i] >> v[i];
        sum += v[i];
    }

    std::vector<long long int> weights(sum + 1, 1e9);
    weights[0] = 0;
    long long int val = 0;
    for (int i = 0; i < N; i++) {
        for (int j = sum - v[i]; j >= 0; j--) {
            if (weights[j] != 1e9) {
                weights[j + v[i]] = std::min(weights[j + v[i]], weights[j] + w[i]);
                if (weights[j + v[i]] <= W) {
                    val = std::max(val, j + v[i]);
                }
            }
        }
    }
    // for (auto& v : weights) {
    //     std::cout << v << " ";
    // }
    // std::cout << std::endl;
    std::cout << val << std::endl;
}
