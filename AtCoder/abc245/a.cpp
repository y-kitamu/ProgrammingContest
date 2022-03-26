/*
 * a.cpp
 *
 * Create Date : 2022-03-26 20:57:14
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    if (A == C) {
        if (B <= D) {
            std::cout << "Takahashi" << std::endl;
        } else {
            std::cout << "Aoki" << std::endl;
        }
    } else if (A < C) {
        std::cout << "Takahashi" << std::endl;
    } else {
        std::cout << "Aoki" << std::endl;
    }
}
