/*
 * a.cpp
 *
 * Create Date : 2021-11-27 20:57:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    if ((s1[0] == '#' && s1[1] == '.' && s2[0] == '.' && s2[1] == '#') ||
        (s1[1] == '#' && s1[0] == '.' && s2[1] == '.' && s2[0] == '#')) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
}
