/*
 * b.cpp
 *
 * Create Date : 2021-10-02 21:01:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S, T;
    std::cin >> S >> T;

    if (S == T) {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    for (int i = 0; i < S.length() - 1; i++) {
        std::swap(S[i], S[i + 1]);
        if (S == T) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        std::swap(S[i], S[i + 1]);
    }
    std::cout << "No" << std::endl;
}
