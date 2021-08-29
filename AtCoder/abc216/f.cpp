/*
 * f.cpp
 *
 * Create Date : 2021-08-29 22:15:07
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
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for (int i = 0; i < N; i++) {
        int max = A[i];
        int res = max - B[i];
        for (int j = 0; j < N; j++) {
            if (A[j] > A[i]) {
                continue;
            }
        }
    }
}
