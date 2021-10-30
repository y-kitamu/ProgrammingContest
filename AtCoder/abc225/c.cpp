/*
 * c.cpp
 *
 * Create Date : 2021-10-30 21:04:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, M;
    std::cin >> N >> M;

    bool flag = true;
    long long int start;
    std::cin >> start;
    if ((start - 1) % 7 > (start + M - 2) % 7) {
        flag = false;
    }
    long long int b;
    for (long long int j = 1; j < M; j++) {
        std::cin >> b;
        flag &= b == (start + j);
    }
    for (long long int i = 1; i < N; i++) {
        start += 7;
        for (long long int j = 0; j < M; j++) {
            std::cin >> b;
            flag &= b == (start + j);
        }
    }

    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
