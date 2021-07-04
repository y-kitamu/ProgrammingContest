/*
 * c.cpp
 *
 * Create Date : 2021-07-04 21:04:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;
    std::vector<long long int> number(N);
    for (int i = 0; i < N; i++) {
        std::cin >> number[i];
    }

    long long int base = K / N;
    long long int res = K % N;
    std::vector<long long int> sorted = number;
    std::sort(sorted.begin(), sorted.end());
    long long int part = sorted[res];

    for (int i = 0; i < N; i++) {
        if (number[i] < part) {
            std::cout << base + 1 << std::endl;
        } else {
            std::cout << base << std::endl;
        }
    }
}
