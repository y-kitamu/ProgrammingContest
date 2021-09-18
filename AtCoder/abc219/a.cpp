/*
 * a.cpp
 *
 * Create Date : 2021-09-18 21:00:08
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int x;
    std::cin >> x;

    if (x < 40) {
        std::cout << 40 - x << std::endl;
    } else if (x < 70) {
        std::cout << 70 - x << std::endl;
    } else if (x < 90) {
        std::cout << 90 - x << std::endl;
    } else {
        std::cout << "expert" << std::endl;
    }
}
