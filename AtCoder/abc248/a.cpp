/*
 * a.cpp
 *
 * Create Date : 2022-04-16 20:59:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    std::vector<int> flag(10, 0);
    for (auto& c : S) {
        flag[(int)(c - '0')] = 1;
    }

    for (int i = 0; i < 10; i++) {
        if (flag[i] == 0) {
            std::cout << i << std::endl;
        }
    }
}
