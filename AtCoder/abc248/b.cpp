/*
 * b.cpp
 *
 * Create Date : 2022-04-16 21:01:54
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int A, B, K;
    std::cin >> A >> B >> K;

    int cnt = 0;
    while (A < B) {
        A *= K;
        cnt++;
    }

    std::cout << cnt << std::endl;
}
