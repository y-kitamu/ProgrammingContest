/*
 * a.cpp
 *
 * Create Date : 2022-04-23 20:59:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B, C, D, E, F, X;
    std::cin >> A >> B >> C >> D >> E >> F >> X;

    int r0 = X / (A + C);
    int s0 = std::min(X - r0 * (A + C), A);
    int d0 = (r0 * A + s0) * B;

    int r1 = X / (D + F);
    int s1 = std::min(X - r1 * (D + F), D);
    int d1 = (r1 * D + s1) * E;
    if (d0 > d1) {
        std::cout << "Takahashi" << std::endl;
    } else if (d0 < d1) {
        std::cout << "Aoki" << std::endl;
    } else {
        std::cout << "Draw" << std::endl;
    }
}
