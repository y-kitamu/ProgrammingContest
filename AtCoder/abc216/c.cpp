/*
 * c.cpp
 *
 * Create Date : 2021-08-29 21:05:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    std::vector<int> ops;

    while (N > 0) {
        if (N & 1) {
            ops.emplace_back(0);
            N--;
        } else {
            ops.emplace_back(1);
            N >>= 1;
        }
    }
    int n = ops.size();
    for (int i = 0; i < n; i++) {
        if (ops[n - i - 1] == 0) {
            std::cout << "A";
        } else {
            std::cout << "B";
        }
    }
    std::cout << std::endl;
}
