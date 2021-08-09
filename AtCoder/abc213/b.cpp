/*
 * b.cpp
 *
 * Create Date : 2021-08-08 21:05:00
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


std::vector<int> index_sort(std::vector<int>& vec) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::sort(idx.begin(), idx.end(), [&vec](int lhs, int rhs) { return vec[lhs] < vec[rhs]; });
    return idx;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto idx = index_sort(A);
    std::cout << idx[N - 2] + 1 << std::endl;
}
