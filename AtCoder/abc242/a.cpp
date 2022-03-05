/*
 * a.cpp
 *
 * Create Date : 2022-03-05 20:55:47
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int X, A, B, C;
    std::cin >> A >> B >> C >> X;
    if (X <= A) {
        std::cout << 1.0 << std::endl;
    } else if (X <= B) {
        std::cout << std::setprecision(10) << std::fixed << double(C) / (B - A) << std::endl;
    } else {
        std::cout << 0.0 << std::endl;
    }
}
