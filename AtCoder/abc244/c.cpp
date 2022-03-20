/*
 * c.cpp
 *
 * Create Date : 2022-03-20 21:05:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> flag(2 * N + 1, 0);

    while (true) {
        for (int j = 0; j < 2 * N + 1; j++) {
            if (flag[j] == 0) {
                flag[j] = 1;
                std::cout << j + 1 << std::endl;
                break;
            }
        }
        int val;
        std::cin >> val;
        if (val == 0) {
            break;
        }
        flag[val - 1] = 1;
    }
}
