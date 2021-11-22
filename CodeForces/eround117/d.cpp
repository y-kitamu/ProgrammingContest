/*
 * d.cpp
 *
 * Create Date : 2021-11-22 19:29:48
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        long long int a, b, x;
        std::cin >> a >> b >> x;
        if (x > a && x > b) {
            std::cout << "NO" << std::endl;
            continue;
        }

        bool flag = false;
        while (a >= x || b >= x) {
            if (a < b) {
                std::swap(a, b);
            }
            if (a == x || b == x) {
                flag = true;
                break;
            }
            long long int d = a - b;
            if (d == 0 || b == 0) {
                break;
            }
            if ((a - x) % d == 0 || (a - x) % b == 0) {
                flag = true;
                break;
            }
            a = a % b;
        }
        if (flag) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}
