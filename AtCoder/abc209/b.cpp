/*
 * b.cpp
 *
 * Create Date : 2021-07-10 21:01:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        sum += a;
        if (i % 2 == 1) {
            sum -= 1;
        }
    }
    if (sum <= X) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
