/*
 * a.cpp
 *
 * Create Date : 2021-11-28 20:58:53
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    long long int idx = 1;
    long long int start = 0;
    long long int sum = 0;
    while (idx < N) {
        if (S[idx - 1] != S[idx]) {
            int diff = idx - start;
            sum += diff * (diff - 1ll) / 2ll;
            start = idx;
        }
        idx++;
    }
    long long int diff = idx - start;
    sum += diff * (diff - 1ll) / 2ll;

    std::cout << sum << std::endl;
}
