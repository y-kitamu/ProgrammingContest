/*
 * prison.cpp
 *
 * Create Date : 2020-04-25 16:36:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {
    int N, M;
    std::cin >> N >> M;

    int min = 1;
    int max = N;
    for (int i = 0; i < M; i++) {
        int l, r;
        std::cin >> l >> r;
        if (min < l) {
            min = l;
        }
        if (max > r) {
            max = r;
        }
    }
    if (max >= min) {
        std::cout << max - min + 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}
