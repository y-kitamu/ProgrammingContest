/*
 * b.cpp
 *
 * Create Date : 2021-08-21 21:01:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    unsigned long long N;
    std::cin >> N;

    for (int i = 63; i >= 0; i--) {
        if ((N >> i) & 1) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << 0 << std::endl;
}
