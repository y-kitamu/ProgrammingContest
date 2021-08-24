/*
 * d.cpp
 *
 * Create Date : 2021-08-24 20:26:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<long long int> w(N), v(N);
    for (int i = 0; i < N; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<long long int> value(W + 1, 0);

    for (int i = 0; i < N; i++) {
        for (int j = W - w[i]; j >= 0; j--) {
            value[j + w[i]] = std::max(value[j + w[i]], value[j] + v[i]);
        }
    }
    std::cout << value[W] << std::endl;
}
