/*
 * a.cpp
 *
 * Create Date : 2021-07-04 20:56:57
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;
    if (A <= B && B <= 6 * A) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
