/*
 * b.cpp
 *
 * Create Date : 2021-09-19 22:28:17
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


std::vector<int> index_sort(std::vector<int>& vec_a, std::vector<int>& vec_b) {
    std::vector<int> idx(vec_a.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&vec_a, &vec_b](auto& lhs, auto& rhs) {
        if (vec_a[lhs] == vec_a[rhs]) {
            return vec_b[lhs] > vec_b[rhs];
        }
        return vec_a[lhs] < vec_a[rhs];
    });
    return idx;
}

std::vector<int> reorder(std::vector<int>& src, std::vector<int>& idx) {
    std::vector<int> dst(src.size());
    for (int i = 0; i < idx.size(); i++) {
        dst[i] = src[idx[i]];
    }
    return dst;
}


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(M), b(M);
    for (int i = 0; i < M; i++) {
        std::cin >> a[i] >> b[i];
    }

    auto idx = index_sort(a, b);
    auto sa = reorder(a, idx);
    auto sb = reorder(b, idx);

    std::vector<int> cnt(M, 1e9);
    for (int i = 0; i < M; i++) {
        auto itr = std::lower_bound(cnt.begin(), cnt.end(), sb[i]);
        itr[0] = std::min(itr[0], sb[i]);
        // std::cout << i << ", " << sb[i] << " , " << std::distance(cnt.begin(), itr) << std::endl;
    }
    auto itr = std::lower_bound(cnt.begin(), cnt.end(), 1e9);
    // for (auto i = cnt.begin(); i != itr; i++) {
    //     std::cout << *i << " ";
    // }
    // std::cout << std::endl;
    int max = std::distance(cnt.begin(), itr);
    std::cout << max << std::endl;
}
