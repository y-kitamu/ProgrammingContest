/*
 * fizzbuzzsum.cpp
 *
 * Create Date : 2020-04-12 21:04:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


int main() {
    long long int N;
    std::cin >> N;

    long long int sum = (N + 1) * N / 2;
    
    long long int sum_3 = (N / 3) * (3 + N - N % 3) / 2;
    long long int sum_5 = (N / 5) * (5 + N - N % 5) / 2;
    long long int sum_15 = (N / 15) * (15 + N - N % 15) / 2;

    std::cout << sum + sum_15 - sum_3 - sum_5 << std::endl;
}
