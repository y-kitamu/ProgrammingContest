/*
 * a.cpp
 *
 * Create Date : 2021-07-18 20:57:56
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int A1, A2, A3;
    std::cin >> A1 >> A2 >> A3;

    long long int r0 = A2 - A1;
    long long int r1 = A3 - A2;

    if (r0 == r1) {
        std::cout << 0 << std::endl;
    } else if (r0 > r1) {
        std::cout << r0 - r1 << std::endl;
    } else {
        std::cout << (r1 - r0) / 2 + (r1 - r0) % 2 * 2 << std::endl;
    }
}
