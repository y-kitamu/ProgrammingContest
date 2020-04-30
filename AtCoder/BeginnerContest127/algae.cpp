/*
 * algae.cpp
 *
 * Create Date : 2020-04-25 16:33:01
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {
    int r, D, x;
    std::cin >> r >> D >> x;
    for (int i = 0; i < 10; i++) {
        x = r * x - D;
        std::cout << x << std::endl;
    }
}
