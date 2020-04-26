/*
 * gacha.cpp
 *
 * Create Date : 2020-04-26 21:05:42
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <set>


int main() {
    int N;
    std::cin >> N;

    std::set<std::string> gacha;
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        gacha.insert(str);
    }
    std::cout << gacha.size() << std::endl;
}
