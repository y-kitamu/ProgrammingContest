/*
 * b.cpp
 *
 * Create Date : 2021-11-20 21:03:39
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;
    X--;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
    }

    std::vector<bool> flag(N, false);
    int idx = X;
    int cnt = 0;
    while (!flag[idx]) {
        flag[idx] = true;
        idx = A[idx];
        cnt++;
    }

    std::cout << cnt << std::endl;
}
