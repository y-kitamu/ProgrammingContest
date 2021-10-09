/*
 * a.cpp
 *
 * Create Date : 2021-10-09 21:00:01
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string N;
    std::cin >> N;

    while (N.length() != 4) {
        N = '0' + N;
    }

    std::cout << N << std::endl;
}
