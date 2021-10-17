/*
 * e.cpp
 *
 * Create Date : 2021-10-17 21:41:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int X, Y, A, B, C;
    std::cin >> X >> Y >> A >> B >> C;

    // minimum lengths;
    long long int ax = (A + Y - 1) / Y;
    long long int ay = (A + X - 1) / X;
    long long int bx = (B + Y - 1) / Y;
    long long int by = (B + X - 1) / X;
    long long int cx = (C + Y - 1) / Y;
    long long int cy = (C + X - 1) / X;

    // col * 3
    if (ax + bx + cx <= X) {
        std::cout << "Yes" << std::endl;
        return 0;
    }
    // row * 3
    if (ay + by + cy <= Y) {
        std::cout << "Yes" << std::endl;
        return 0;
    }

    long long int res;
    for (int i = 0; i < 3; i++) {
        // col + row * 2
        res = X - (A + Y - 1) / Y;
        if (res > 0 && (B + res - 1) / res + (C + res - 1) / res <= Y) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        // row + col * 2
        res = Y - (A + X - 1) / X;
        if (res > 0 && (B + res - 1) / res + (C + res - 1) / res <= X) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        auto tmp = A;
        A = B;
        B = C;
        C = tmp;
    }

    std::cout << "No" << std::endl;
    return 0;
}
