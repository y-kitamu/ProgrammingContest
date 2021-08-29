/*
 * b.cpp
 *
 * Create Date : 2021-08-29 21:02:56
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> S(N), T(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i] >> T[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (S[i] == S[j] && T[i] == T[j]) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
}
