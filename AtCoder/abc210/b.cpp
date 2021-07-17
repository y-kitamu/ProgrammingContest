/*
 * b.cpp
 *
 * Create Date : 2021-07-17 21:01:53
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '1') {
            if (i % 2 == 0) {
                std::cout << "Takahashi" << std::endl;
            } else {
                std::cout << "Aoki" << std::endl;
            }
            break;
        }
    }
}
