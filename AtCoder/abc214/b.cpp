/*
 * b.cpp
 *
 * Create Date : 2021-08-14 21:02:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

int main() {
    int S, T;
    std::cin >> S >> T;

    int cnt = 0;
    for (int a = 0; a <= 100; a++) {
        for (int b = 0; b <= 100; b++) {
            for (int c = 0; c <= 100; c++) {
                if (a + b + c > S || a * b * c > T) {
                    break;
                }
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}
