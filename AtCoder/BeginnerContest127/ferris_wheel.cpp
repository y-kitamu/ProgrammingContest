/*
 * ferris_wheel.cpp
 *
 * Create Date : 2020-04-25 16:30:18
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {
    int A, B;
    std::cin >> A >> B;
    if (A >= 13) {
        std::cout << B << std::endl;
    } else if (A >= 6) {
        std::cout << B / 2 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}
