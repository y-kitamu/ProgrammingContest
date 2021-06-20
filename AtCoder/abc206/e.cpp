/*
 * e.cpp
 *
 * Create Date : 2021-06-19 21:38:08
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long int calcNum(long long int num) {}


int main() {
    int L, R;
    std::cin >> L >> R;

    long long int sum = 0;
    for (int i = 2; i < L - 1; i++) {
        long long int min = (L + i - 1) / i;
        long long int max = R / i;
        sum += (max - min + 1) * (max - min) / 2;
    }

    for (int i = L; i <= R; i++) {
    }
}
