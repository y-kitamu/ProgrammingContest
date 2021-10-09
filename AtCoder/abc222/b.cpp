/*
 * b.cpp
 *
 * Create Date : 2021-10-09 21:01:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, P;
    std::cin >> N >> P;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (a < P) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
