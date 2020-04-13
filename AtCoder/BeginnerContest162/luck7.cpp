/*
 * luck7.cpp
 *
 * Create Date : 2020-04-12 21:00:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <string>
#include <iostream>

int main() {
    std::string N;
    std::cin >> N;
    for (auto c : N) {
        if (c == '7') {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
}
