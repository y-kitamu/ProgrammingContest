/*
 * e.cpp
 *
 * Create Date : 2022-02-19 21:23:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


void solve(int idx, std::vector<int>& X, std::set<int>& set, std::vector<std::vector<int>>& ll,
           std::vector<int>& sorted_v, std::vector<int>& sorted_k, std::vector<int>& ans) {
    std::set<int> tmp;
    for (auto& next : ll[idx]) {
        if (set.find(next) != set.end()) {
            continue;
        }
        solve(idx, X, tmp, ll, sorted_v, sorted_k, ans);
    }
    tmp.insert(X[idx]);
    auto itr = std::lower_bound(sorted_v.begin(), sorted_v.end(), idx);
    if (*itr == idx) {
        auto sitr = tmp.begin();
        for (int i = 0; i < sorted_k[i]; i++, sitr++) {
        }
        auto i = std::distance(sorted_v.begin(), itr);
        ans[i] = *sitr;
    }
    set.insert(tmp.begin(), tmp.end());
}


int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> X(N);
    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        ll[a].emplace_back(b);
        ll[b].emplace_back(a);
    }

    std::vector<int> V(Q), K(Q);
    for (int q = 0; q < Q; q++) {
        std::cin >> V[q] >> K[q];
        V[q]--;
        K[q]--;
    }

    std::vector<int> idx(Q);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&V](auto& lhs, auto& rhs) { return V[lhs] < V[rhs]; });

    std::vector<int> sorted_v(Q), sorted_k(Q);
    for (int i = 0; i < Q; i++) {
        sorted_v[i] = V[idx[i]];
        sorted_k[i] = K[idx[i]];
    }

    std::vector<int> sorted_ans(Q);
    std::set<int> set;
    solve(0, X, set, ll, sorted_v, sorted_k, sorted_ans);

    std::vector<int> rev(Q);
    std::iota(rev.begin(), rev.end(), 0);
    std::sort(rev.begin(), rev.end(), [&idx](auto& lhs, auto& rhs) { return idx[lhs] < idx[rhs]; });

    for (int i = 0; i < Q; i++) {
        std::cout << sorted_ans[rev[i]] << std::endl;
    }
}
