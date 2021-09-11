/*
 * b.cpp
 *
 * Create Date : 2021-09-11 21:01:37
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string s = "";

    for (int i = 0; i < 26; i++) {
        int p;
        std::cin >> p;
        s += (char)('a' + p - 1);
    }

    std::cout << s << std::endl;
}
