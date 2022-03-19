/*
 * a.cpp
 *
 * Create Date : 2022-03-19 20:57:48
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long gcd(long long a, long long b) {
    while (b > 0) {
        long long tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int main() {
    long long L, R;
    std::cin >> L >> R;

    long long diff = R - L;
    for (long long d = 0; d < diff; d++) {
        for (long long off = 0; off <= d; off++) {
            long long min = L + off;
            long long max = min + diff - d;
            if (gcd(max, min) == 1) {
                std::cout << diff - d << std::endl;
                return 0;
            }
        }
    }
}
