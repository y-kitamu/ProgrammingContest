/*
 * c.cpp
 *
 * Create Date : 2021-11-22 19:00:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        long long k, x;
        std::cin >> k >> x;

        if (k * k <= x) {
            std::cout << 2 * k - 1 << std::endl;
            continue;
        }

        long long half = (k + 1) * k / 2;
        if (half >= x) {
            long long r = std::sqrt(2 * x);
            while (r * (r + 1) / 2 < x) {
                r++;
            }
            std::cout << r << std::endl;
        } else {
            long long res = x - half;
            long long min = 0;
            long long max = k - 1;
            while (min != max) {
                long long mid = (min + max + 1) / 2;
                long long sum = (2 * k - mid - 1) * mid / 2;
                if (sum < res) {
                    min = mid;
                } else {
                    max = mid - 1;
                }
            }
            std::cout << k + min + 1 << std::endl;
        }
    }
}
