/*
 * a.cpp
 *
 * Create Date : 2021-10-17 20:59:05
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int X;
    std::cin >> X;

    if (X > 0 && X % 100 == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
