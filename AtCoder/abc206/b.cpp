/*
 * b.cpp
 *
 * Create Date : 2021-06-19 21:02:05
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int d = 1;
    for (; d * (d + 1) / 2 < N; d++) {
    }
    std::cout << d << std::endl;
}
