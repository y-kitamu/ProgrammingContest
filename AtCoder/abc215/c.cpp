/*
 * c.cpp
 *
 * Create Date : 2021-08-21 21:03:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    int K;
    std::cin >> S >> K;

    std::sort(S.begin(), S.end());

    int idx = 1;
    std::string prev = S;
    while (idx < K) {
        std::next_permutation(S.begin(), S.end());
        idx++;
    }

    std::cout << S << std::endl;
}
