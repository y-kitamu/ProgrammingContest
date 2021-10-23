/*
 * a.cpp
 *
 * Create Date : 2021-10-23 20:58:37
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    if (S[S.length() - 1] == 'r') {
        std::cout << "er" << std::endl;
    } else {
        std::cout << "ist" << std::endl;
    }
}
