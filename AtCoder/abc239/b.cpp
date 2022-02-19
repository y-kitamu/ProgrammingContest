/*
 * b.cpp
 *
 * Create Date : 2022-02-19 21:02:51
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int X;
    std::cin >> X;

    if (X > 0) {
        std::cout << X / 10 << std::endl;
    } else {
        std::cout << (X - 9) / 10 << std::endl;
    }
}
