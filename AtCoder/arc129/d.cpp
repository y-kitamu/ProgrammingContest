/*
 * d.cpp
 *
 * Create Date : 2021-11-21 22:46:24
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int sum = 0;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    if (sum != 0) {
        std::cout << -1 << std::endl;
    }
}
