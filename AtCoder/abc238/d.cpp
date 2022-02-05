/*
 * d.cpp
 *
 * Create Date : 2022-02-05 21:31:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        long long int a, s;
        std::cin >> a >> s;

        long long int sum = a * 2;
        if (s < sum) {
            std::cout << "No" << std::endl;
            continue;
        }

        long long int res = s - sum;
        if ((res & a) == 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
}
