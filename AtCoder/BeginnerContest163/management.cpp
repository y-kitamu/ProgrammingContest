/*
 * management.cpp
 *
 * Create Date : 2020-04-19 21:09:32
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> sub(N, 0);

    for (int i = 1; i < N; i++) {
        int a;
        std::cin >> a;
        sub[a - 1]++;
    }

    for (int i = 0; i < N; i++) {
        std::cout << sub[i] << std::endl;
    }
}
