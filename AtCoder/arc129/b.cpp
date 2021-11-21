/*
 * b.cpp
 *
 * Create Date : 2021-11-21 21:28:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> L(N), R(N);
    for (int i = 0; i < N; i++) {
        std::cin >> L[i] >> R[i];
    }

    std::vector<int> ans(N, 0);
    int lmax = L[0], rmin = R[0];
    for (int i = 1; i < N; i++) {
        lmax = std::max(L[i], lmax);
        rmin = std::min(R[i], rmin);
        if (lmax <= rmin) {
            ans[i] = 0;
        } else {
            ans[i] = (lmax - rmin + 1) / 2;
        }
    }
    for (auto& val : ans) {
        std::cout << val << std::endl;
    }
}
