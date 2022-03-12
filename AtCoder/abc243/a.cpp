/*
 * a.cpp
 *
 * Create Date : 2022-03-12 20:58:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B, C, V;
    std::cin >> V >> A >> B >> C;

    int res = V % (A + B + C);

    if (res - A < 0) {
        std::cout << "F" << std::endl;
    } else if (res - A - B < 0) {
        std::cout << "M" << std::endl;
    } else {
        std::cout << "T" << std::endl;
    }
}
