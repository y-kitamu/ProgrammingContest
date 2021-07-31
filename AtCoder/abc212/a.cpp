/*
 * a.cpp
 *
 * Create Date : 2021-07-31 20:54:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;

    if (0 < A and B == 0) {
        std::cout << "Gold" << std::endl;
    } else if (A == 0 and 0 < B) {
        std::cout << "Silver" << std::endl;
    } else if (0 < A and 0 < B) {
        std::cout << "Alloy" << std::endl;
    }
}
