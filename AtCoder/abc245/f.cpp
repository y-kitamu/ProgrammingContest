/*
 * f.cpp
 *
 * Create Date : 2022-03-26 22:16:14
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        ll[u].emplace_back(v);
    }
}
