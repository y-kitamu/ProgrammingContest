/*
 * d.cpp
 *
 * Create Date : 2021-06-19 21:10:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i]--;
    }

    std::vector<std::vector<int>> ll(2e5);
    for (int i = 0; i < N / 2; i++) {
        if (A[i] != A[N - i - 1]) {
            ll[A[i]].emplace_back(A[N - i - 1]);
        }
    }

    std::vector<int> roots(2e5);
    std::iota(roots.begin(), roots.end(), 0);

    auto find_root = [&roots](int idx) {
        std::vector<int> updates;
        while (roots[idx] != idx) {
            updates.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& i : updates) {
            roots[i] = idx;
        }
        return idx;
    };

    for (int i = 0; i < 2e5; i++) {
        auto lhs = find_root(i);
        for (auto& val : ll[i]) {
            auto rhs = find_root(val);
            roots[rhs] = lhs;
        }
    }

    int sum = 0;
    for (int i = 0; i < 2e5; i++) {
        if (roots[i] != i) {
            sum++;
        }
    }

    std::cout << sum << std::endl;
}
