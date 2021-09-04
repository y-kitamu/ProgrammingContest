/*
 * c.cpp
 *
 * Create Date : 2021-09-04 21:04:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> dst(N);
    for (int i = 0; i < N; i++) {
        int p;
        std::cin >> p;
        dst[--p] = i + 1;
    }

    for (int i = 0; i < N; i++) {
        std::cout << dst[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
