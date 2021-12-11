/*
 * c.cpp
 *
 * Create Date : 2021-12-11 21:04:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    for (int i = 0; i < Q; i++) {
        int x;
        std::cin >> x;
        auto ptr = std::lower_bound(A.begin(), A.end(), x);
        int little = std::distance(A.begin(), ptr);
        std::cout << N - little << std::endl;
    }
}
