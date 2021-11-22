/*
 * a.cpp
 *
 * Create Date : 2021-11-22 18:28:10
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        int bx, by;
        std::cin >> bx >> by;
        if ((bx + by) % 2 == 1) {
            std::cout << -1 << " " << -1 << std::endl;
            continue;
        }
        if (bx < 0 && by < 0) {
            std::cout << -1 << " " << -1 << std::endl;
            continue;
        }
        int sum = (bx + by) / 2;
        if (bx < 0) {
            if (sum <= by) {
                std::cout << 0 << " " << sum << std::endl;
            } else {
                std::cout << -1 << " " << -1 << std::endl;
            }
        } else if (by < 0) {
            if (sum <= bx) {
                std::cout << sum << " " << 0 << std::endl;
            } else {
                std::cout << -1 << " " << -1 << std::endl;
            }
        } else {
            int cx = std::min(sum, bx);
            int cy = std::max(0, sum - cx);
            std::cout << cx << " " << cy << std::endl;
        }
    }
}
