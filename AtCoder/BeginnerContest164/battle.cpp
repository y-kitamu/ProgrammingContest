/*
 * battle.cpp
 *
 * Create Date : 2020-04-26 21:02:59
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    while (true) {
        C = C - B;
        if (C <= 0) {
            std::cout << "Yes" << std::endl;
            break;
        }
        A = A - D;
        if (A <= 0) {
            std::cout << "No" << std::endl;
            break;
        }
    }
}
