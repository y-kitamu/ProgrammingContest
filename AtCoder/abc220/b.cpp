/*
 * b.cpp
 *
 * Create Date : 2021-09-26 21:01:53
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int K, A, B;
    std::cin >> K >> A >> B;

    auto conv = [&K](long long int val) {
        long long int scale = 1;
        long long int out = 0;
        while (val > 0) {
            auto res = val % 10;
            out += res * scale;
            scale *= K;
            val /= 10;
        }
        return out;
    };

    std::cout << conv(A) * conv(B) << std::endl;
}
