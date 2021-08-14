/*
 * a.cpp
 *
 * Create Date : 2021-08-14 20:54:39
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    if (N <= 125) {
        std::cout << 4 << std::endl;
    } else if (N <= 211) {
        std::cout << 6 << std::endl;
    } else {
        std::cout << 8 << std::endl;
    }
}
