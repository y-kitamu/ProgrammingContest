/*
 * c.cpp
 *
 * Create Date : 2021-06-13 21:04:33
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    if (C % 2 == 0) {
        A = std::abs(A);
        B = std::abs(B);
    }
    if (A > B) {
        std::cout << ">" << std::endl;
    } else if (A == B) {
        std::cout << "=" << std::endl;
    } else {
        std::cout << "<" << std::endl;
    }
}
