/*
 * a.cpp
 *
 * Create Date : 2021-11-13 20:59:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K, A;
    std::cin >> N >> K >> A;
    for (int i = 0; i < K - 1; i++) {
        A++;
        if (A > N) {
            A -= N;
        }
    }
    std::cout << A << std::endl;
}
