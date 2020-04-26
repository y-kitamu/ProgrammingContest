/*
 * sheep_and_wolves.cpp
 *
 * Create Date : 2020-04-26 21:00:23
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {
    int S, W;
    std::cin >> S >> W;

    if (S <= W) {
        std::cout << "unsafe" << std::endl;
    } else {
        std::cout << "safe" << std::endl;
    }

}
