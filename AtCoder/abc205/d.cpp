/*
 * d.cpp
 *
 * Create Date : 2021-06-13 21:09:01
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

using ll = long long int;


std::vector<int> index_sort(std::vector<ll>& vec) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&vec](auto& lhs, auto& rhs) { return vec[lhs] < vec[rhs]; });
    return idx;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<ll> K(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> K[i];
    }

    auto sort_idx = index_sort(K);

    ll a_idx = 0;
    std::vector<ll> ans(Q);
    for (int i = 0; i < Q; i++) {
        ll val = K[sort_idx[i]] + a_idx;
        while (a_idx < N && val >= A[a_idx]) {
            val++;
            a_idx++;
        }
        ans[sort_idx[i]] = val;
    }

    for (int i = 0; i < Q; i++) {
        std::cout << ans[i] << std::endl;
    }
}
