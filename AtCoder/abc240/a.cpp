/*
 * a.cpp
 *
 * Create Date : 2022-02-20 20:58:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int a, b;
    std::cin >> a >> b;

    if (std::abs(a - b) == 1) {
        std::cout << "Yes" << std::endl;
    } else if ((a == 1 && b == 10) || (a == 10 && b == 1)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
