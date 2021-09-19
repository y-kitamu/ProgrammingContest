/*
 * c.cpp
 *
 * Create Date : 2021-09-19 23:04:51
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());

    long long int res = K;
    for (int i = 0; i < N - 1; i++) {
        res -= A[N - 1] - A[i];
    }
    if (res >= 0) {
        long long int ans = A[N - 1] + res / N;
        std::cout << ans << std::endl;
        return 0;
    }
}
