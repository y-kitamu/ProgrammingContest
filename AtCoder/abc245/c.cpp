/*
 * c.cpp
 *
 * Create Date : 2022-03-26 21:05:28
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> flag(2, 1);
    for (int i = 1; i < N; i++) {
        std::vector<int> next(2, 0);
        if (flag[0] == 1) {
            if (std::abs(A[i - 1] - A[i]) <= K) {
                next[0] = 1;
            }
            if (std::abs(A[i - 1] - B[i]) <= K) {
                next[1] = 1;
            }
        }
        if (flag[1] == 1) {
            if (std::abs(B[i - 1] - A[i]) <= K) {
                next[0] = 1;
            }
            if (std::abs(B[i - 1] - B[i]) <= K) {
                next[1] = 1;
            }
        }
        flag = next;
    }
    if (flag[0] == 1 || flag[1] == 1) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
