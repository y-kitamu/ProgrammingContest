/*
 * b.cpp
 *
 * Create Date : 2021-10-17 21:01:32
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    auto min = S;
    auto max = S;

    for (int i = 0; i < S.length(); i++) {
        S = S.substr(1) + S[0];
        if (S < min) {
            min = S;
        }
        if (S > max) {
            max = S;
        }
    }
    std::cout << min << std::endl;
    std::cout << max << std::endl;
}
