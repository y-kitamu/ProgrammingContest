/*
 * c.cpp
 *
 * Create Date : 2021-12-05 21:20:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int sum = 0;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum ^= A[i];
    }

    if (N == 1) {
        std::cout << "Win" << std::endl;
        return 0;
    }
    if (N == 2) {
        std::cout << "Lose" << std::endl;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if ((sum ^ A[i]) == 0) {
            std::cout << "Win" << std::endl;
            return 0;
        }
    }
    if (N % 2 == 0) {
        std::cout << "Lose" << std::endl;
    } else {
        std::cout << "Win" << std::endl;
    }
}
