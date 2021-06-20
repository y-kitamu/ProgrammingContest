/*
 * a.cpp
 *
 * Create Date : 2021-06-19 20:58:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    int val = 1.08 * N;
    if (val < 206) {
        std::cout << "Yay!" << std::endl;
    } else if (val == 206) {
        std::cout << "so-so" << std::endl;
    } else {
        std::cout << ":(" << std::endl;
    }
}
