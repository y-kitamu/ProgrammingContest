/*
 * d.cpp
 *
 * Create Date : 2022-03-26 21:11:10
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N + 1), C(N + M + 1);
    for (int i = 0; i <= N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i <= N + M; i++) {
        std::cin >> C[i];
    }

    std::vector<int> B(M + 1);
    for (int i = M; i >= 0; i--) {
        int res = C[i + N];
        int max_m = std::min(i + N, M);
        for (int m = max_m; m > i; m--) {
            res -= A[i + N - m] * B[m];
        }
        B[i] = res / A[N];
    }

    for (int i = 0; i <= M; i++) {
        std::cout << B[i];
        if (i < M) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
