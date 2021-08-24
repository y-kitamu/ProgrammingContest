/*
 * g.cpp
 *
 * Create Date : 2021-08-24 21:34:31
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int dfs(int idx, std::vector<int>& cnts, std::vector<std::vector<int>>& ll) {
    if (ll[idx].size() == 0) {
        cnts[idx] = 0;
    }
    if (cnts[idx] != -1) {
        return cnts[idx];
    }

    int cnt = 0;
    for (auto& next : ll[idx]) {
        cnt = std::max(cnt, dfs(next, cnts, ll));
    }
    cnts[idx] = cnt + 1;
    return cnts[idx];
}


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        ll[x].emplace_back(y);
    }

    std::vector<int> cnts(N, -1);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnts[i] == -1) {
            ans = std::max(ans, dfs(i, cnts, ll));
        }
    }
    std::cout << ans << std::endl;
}
