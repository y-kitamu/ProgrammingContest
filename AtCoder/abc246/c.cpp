/*
 * c.cpp
 *
 * Create Date : 2022-04-02 21:06:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, K, X;
    std::cin >> N >> K >> X;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        long long int c = std::min(A[i] / X, K);
        K -= c;
        A[i] -= c * X;
    }

    std::sort(A.begin(), A.end(), std::greater<>());
    long long int cost = 0;
    for (int i = K; i < N; i++) {
        cost += A[i];
    }

    std::cout << cost << std::endl;
}
