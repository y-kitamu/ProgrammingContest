/*
 * a.cpp
 *
 * Create Date : 2021-07-17 20:58:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, A, X, Y;
    std::cin >> N >> A >> X >> Y;

    long long int sum = std::min(N, A) * X;
    if (N > A) {
        sum += (N - A) * Y;
    }

    std::cout << sum << std::endl;
}
