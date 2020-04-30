/*
 * cell_distance.cpp
 *
 * Create Date : 2020-04-25 17:37:13
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>


#define MAX 1000000007


long long int calc_combi(long long int n, long long int k) {
    double combi =  1;
    for (int i = 1, j = n; i <= k; i++, j--) {
        combi *= j;
        combi /= i;
    }
    while (combi > MAX) {
        combi -= MAX;
    }
    return combi;
}


int calc_cost(long long int n, long long int m, long long int k) {
    long long int combi = calc_combi(m * n - 2, k - 2);
    long long int sum = 0;
    for (long long int i = 1; i < n; i++) {
        sum += i * (n - i) * m * m * combi;
        sum %= MAX;
    }
    return sum;
}


int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::cout << (calc_cost(N, M, K) + calc_cost(M, N, K)) % MAX << std::endl;
}
