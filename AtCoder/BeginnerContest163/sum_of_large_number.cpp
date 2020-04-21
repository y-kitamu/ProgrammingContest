/*
 * sum_of_large_number.cpp
 *
 * Create Date : 2020-04-19 21:14:31
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {

    int N, K;
    std::cin >> N >> K;

    long long int MAX = 1000000007;
    long long int min = 0, max = 0;
    long long int idx_min = 0, idx_max = N;
    for (;idx_min < K; idx_min++, idx_max--) {
        min += idx_min;
        max += idx_max;
    }
    long long int sum = 0;
    for (;idx_min <= N + 1; idx_min++, idx_max--) {
        sum += max - min + 1;
        sum = sum % MAX;
        min += idx_min;
        max += idx_max;
    }
    std::cout << sum << std::endl;
}
