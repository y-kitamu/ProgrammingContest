/*
 * b.cpp
 *
 * Create Date : 2021-06-14 19:51:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

using ll = long long int;

int main() {
    ll N;
    std::cin >> N;
    ll sum = 0;
    std::vector<int> A(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    std::sort(A.begin(), A.end());
    ll mid = N / 2;
    double val = A[mid] / 2.0;

    ll ins = 0;
    ll i = 0;
    for (; i < N && A[i] <= A[mid]; i++) {
        ins += A[i];
    }
    double ans = (double)(sum - ins - A[mid] * (N - i)) / N + val;
    std::cout << std::fixed << std::setprecision(10) << ans << std::endl;
}
