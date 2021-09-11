/*
 * a.cpp
 *
 * Create Date : 2021-09-11 20:56:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;
    if (S[N - 1] == 'o') {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
