/*
 * b.cpp
 *
 * Create Date : 2021-11-22 18:45:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n, a, b;
        std::cin >> n >> a >> b;
        int half = n / 2;
        if (a > half + 1 || b < half) {
            std::cout << -1 << std::endl;
            continue;
        }
        if ((b == half && a <= half) || (a == half + 1 && b >= half + 1)) {
            std::cout << -1 << std::endl;
            continue;
        }

        std::cout << a;
        int cnt = 0;
        for (int j = 0; cnt < half - 1; j++) {
            if (n - j == b) {
                continue;
            }
            std::cout << " " << n - j;
            cnt++;
        }
        std::cout << " " << b;
        cnt = 0;
        for (int j = 1; cnt < half - 1; j++) {
            if (j == a) {
                continue;
            }
            std::cout << " " << j;
            cnt++;
        }
        std::cout << std::endl;
    }
}
