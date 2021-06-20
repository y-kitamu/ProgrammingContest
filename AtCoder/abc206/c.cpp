/*
 * c.cpp
 *
 * Create Date : 2021-06-19 21:05:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    std::map<int, int> map;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if (map.find(A[i]) == map.end()) {
            map[A[i]] = 0;
        }
        map[A[i]]++;
    }

    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += N - map[A[i]];
    }

    std::cout << sum / 2 << std::endl;
}
