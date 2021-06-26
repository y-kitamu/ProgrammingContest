/*
 * b.cpp
 *
 * Create Date : 2021-06-26 21:01:33
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    long long int val = D * C - B;
    if (val <= 0) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << (A + val - 1) / val << std::endl;
    }
}
