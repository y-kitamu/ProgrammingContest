/*
 * c.cpp
 *
 * Create Date : 2021-08-22 21:53:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Node {
    int val;
    int a_idx;
};


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> a(K);
    for (int i = 0; i < K; i++) {
        std::cin >> a[i];
    }

    int idx = 0;
    std::vector<int> ans(N);
    for (int i = N - K; i > a[K - 1]; i--) {
        ans[idx++] = i;
    }

    std::cout << std::endl;
}
