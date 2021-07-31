/*
 * c.cpp
 *
 * Create Date : 2021-07-31 21:06:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());

    int a = 0, b = 0;
    int min = 2e9;
    while (a != N - 1 || b != M - 1) {
        min = std::min(std::abs(A[a] - B[b]), min);
        if (a == N - 1) {
            b++;
        } else if (b == M - 1) {
            a++;
        } else if (A[a] < B[b]) {
            a++;
        } else {
            b++;
        }
    }
    min = std::min(std::abs(A[a] - B[b]), min);
    std::cout << min << std::endl;
}
