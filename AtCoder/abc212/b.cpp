/*
 * b.cpp
 *
 * Create Date : 2021-07-31 21:02:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string sec;
    std::cin >> sec;
    if (sec[0] == sec[1] && sec[1] == sec[2] && sec[2] == sec[3]) {
        std::cout << "Weak" << std::endl;
    } else {
        bool flag = true;
        for (int i = 0; i < 3; i++) {
            flag &= ((sec[i + 1] - sec[i] + 10) % 10) == 1;
        }
        if (flag) {
            std::cout << "Weak" << std::endl;
        } else {
            std::cout << "Strong" << std::endl;
        }
    }
}
