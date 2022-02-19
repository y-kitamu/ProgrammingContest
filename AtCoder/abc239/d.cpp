/*
 * d.cpp
 *
 * Create Date : 2022-02-19 21:10:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int max = B + D;
    std::vector<int> primes;
    for (int i = 2; i <= max; i++) {
        bool flag = true;
        for (int k = 2; k <= std::sqrt(i + 1); k++) {
            if (i % k == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primes.emplace_back(i);
        }
    }

    for (int i = A; i <= B; i++) {
        auto low = std::lower_bound(primes.begin(), primes.end(), i + C);
        auto high = std::upper_bound(primes.begin(), primes.end(), i + D);
        if (low >= high) {
            std::cout << "Takahashi" << std::endl;
            return 0;
        }
    }
    std::cout << "Aoki" << std::endl;
}
