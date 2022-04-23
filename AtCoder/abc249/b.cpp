/*
 * b.cpp
 *
 * Create Date : 2022-04-23 21:03:27
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    bool has_big = false;
    bool has_small = false;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] - 'a' >= 0 && S[i] - 'a' < 26) {
            has_small = true;
        }
        if (S[i] - 'A' >= 0 && S[i] - 'A' < 26) {
            has_big = true;
        }
        for (int j = 0; j < S.length(); j++) {
            if (i == j) {
                continue;
            }
            if (S[i] == S[j]) {
                std::cout << "No" << std::endl;
                return 0;
            }
        }
    }
    if (has_big && has_small) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
