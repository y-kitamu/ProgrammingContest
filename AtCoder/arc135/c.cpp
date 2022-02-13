/*
 * c.cpp
 *
 * Create Date : 2022-02-13 21:50:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> cnts(30, 0);
    std::vector<int> A(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        for (int j = 0; j < 31; j++) {
            if (A[i] & (1 << j)) {
                cnts[j]++;
            }
        }
    }
}
