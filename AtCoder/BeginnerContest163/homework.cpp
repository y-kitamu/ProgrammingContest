/*
 * homework.cpp
 *
 * Create Date : 2020-04-19 21:06:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {
    int N, M;
    std::cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a;
        std::cin >> a;
        N -= a;
    }

    if (N < 0) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << N << std::endl;
    }

}
