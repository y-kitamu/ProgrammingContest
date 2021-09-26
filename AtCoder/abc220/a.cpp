/*
 * a.cpp
 *
 * Create Date : 2021-09-26 20:55:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    int val = B / C * C;
    if (val < A || B < val) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << val << std::endl;
    }
}
