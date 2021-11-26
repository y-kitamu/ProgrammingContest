/*
 * b.cpp
 *
 * Create Date : 2021-11-26 20:23:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        long long int n;
        std::cin >> n;
        std::vector<long long int> a(n);
        for (int j = 0; j < n; j++) {
            std::cin >> a[j];
        }
        auto index_sort = [&a]() {
            std::vector<int> idx(a.size());
            std::iota(idx.begin(), idx.end(), 0);
            std::sort(idx.begin(), idx.end(), [&a](auto& lhs, auto& rhs) { return a[lhs] > a[rhs]; });
            return idx;
        };
        auto sorted_idx = index_sort();
        std::vector<int> ans(n + 1, 0);
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            auto idx = sorted_idx[j];
            ans[idx + 1] = j / 2 + 1;
            sum += ans[idx + 1] * 2 * a[idx];
            if (j % 2 == 0) {
                ans[idx + 1] *= -1;
            }
        }
        std::cout << sum << std::endl;
        for (int j = 0; j < n + 1; j++) {
            std::cout << ans[j];
            if (j < n) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
