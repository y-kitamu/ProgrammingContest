/*
 * a.cpp
 *
 * Create Date : 2021-08-29 20:59:13
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string xy;
    std::cin >> xy;

    int y = xy[xy.length() - 1] - '0';
    std::string x = xy.substr(0, xy.length() - 2);
    std::cout << x;
    if (y <= 2) {
        std::cout << '-';
    } else if (7 <= y) {
        std::cout << '+';
    }
    std::cout << std::endl;
}
