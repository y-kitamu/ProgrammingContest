/*
 * a.cpp
 *
 * Create Date : 2021-10-30 20:59:23
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) {
        std::cout << 1 << std::endl;
    } else if (S[0] != S[1] && S[0] != S[2] && S[1] != S[2]) {
        std::cout << 6 << std::endl;
    } else {
        std::cout << 3 << std::endl;
    }
}
