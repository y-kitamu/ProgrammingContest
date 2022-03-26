/*
 * e.cpp
 *
 * Create Date : 2022-03-26 21:37:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


std::vector<int> index_sort(std::vector<int>& vec) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [vec](auto& lhs, auto& rhs) { return vec[lhs] < vec[rhs]; });
    return idx;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N), B(N), C(M), D(M);
    std::vector<int> sa(N), sb(N), sc(M), sd(M);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> C[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> D[i];
    }
}
