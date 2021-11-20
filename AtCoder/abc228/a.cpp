/*
 * a.cpp
 *
 * Create Date : 2021-11-20 20:57:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int S, T, X;
    std::cin >> S >> T >> X;

    if (S < T) {
        if ((S <= X) && (X < T)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    } else {
        if ((T <= X) && (X < S)) {
            std::cout << "No" << std::endl;
        } else {
            std::cout << "Yes" << std::endl;
        }
    }
}
