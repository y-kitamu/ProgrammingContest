/*
 * e.cpp
 *
 * Create Date : 2021-11-27 21:27:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        ll[a].emplace_back(b);
    }

    std::vector<int> roots(N, 0);
    auto get_root = [&roots](int idx) {
        std::vector<int> updates;
        while (roots[idx] != idx) {
            updates.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& u : updates) {
            roots[u] = idx;
        }
        return idx;
    };

    std::vector<int> ans(N + 1, 0);
    std::iota(roots.begin(), roots.end(), 0);
    for (int i = N - 1; i >= 0; i--) {
        std::set<int> cnts;
        for (auto& j : ll[i]) {
            int r = get_root(j);
            cnts.insert(r);
        }
        for (auto& val : cnts) {
            roots[val] = i;
        }
        int diff = 1 - cnts.size();
        ans[i] = ans[i + 1] + diff;
    }
    for (int i = 1; i <= N; i++) {
        std::cout << ans[i] << std::endl;
    }
}
