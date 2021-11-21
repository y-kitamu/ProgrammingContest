/*
 * a.cpp
 *
 * Create Date : 2021-11-21 20:55:46
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long N, L, R;
    std::cin >> N >> L >> R;

    long long sum = 0;
    for (int i = 0; i < 63; i++) {
        long long val = 1ll << i;
        if ((val << 1) <= L || R < val) {
            continue;
        }
        if (N & val) {
            sum += val;
            if (val < L) {
                sum -= L - val;
            }
            if (R < (val << 1)) {
                sum -= (val << 1) - R - 1;
                break;
            }
        }
    }
    std::cout << sum << std::endl;
}
