/*
 * d.cpp
 *
 * Create Date : 2022-04-02 21:11:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    auto calc = [](long long int a, long long int b) {
        return a * a * a + a * a * b + b * b * a + b * b * b;
    };

    long long int val = 1e18;
    for (long long int i = 0; i <= 1e6; i++) {
        long long int min = 0, max = 1e6;
        while (min != max) {
            long long int mid = (min + max) / 2;
            if (calc(i, mid) < N) {
                min = mid + 1;
            } else {
                max = mid;
            }
        }
        long long int v = calc(i, min);
        if (v < val) {
            val = v;
        }
    }
    std::cout << val << std::endl;
}
