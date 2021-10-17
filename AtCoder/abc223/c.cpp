/*
 * c.cpp
 *
 * Create Date : 2021-10-17 21:04:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<double> A(N), B(N), C(N);
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
        C[i] = A[i] / B[i];
        sum += C[i];
    }
    double half = sum / 2.0;
    double ans = 0;
    for (int i = 0; i < N; i++) {
        if (half < C[i]) {
            ans += half * B[i];
            break;
        }
        ans += A[i];
        half -= C[i];
    }
    std::cout << std::setprecision(10) << std::fixed << ans << std::endl;
}
