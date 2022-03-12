/*
 * b.cpp
 *
 * Create Date : 2022-03-12 21:01:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    int cnt0 = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        if (A[i] == B[i]) {
            cnt0++;
        }
    }
    std::cout << cnt0 << std::endl;

    int cnt1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (A[i] == B[j]) {
                cnt1++;
            }
        }
    }
    std::cout << cnt1 << std::endl;
}
