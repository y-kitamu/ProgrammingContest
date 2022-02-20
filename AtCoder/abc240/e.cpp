/*
 * e.cpp
 *
 * Create Date : 2022-02-20 21:24:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int dfs(int vert, int cnt, std::vector<int>& flag, std::vector<std::pair<int, int>>& ans,
        std::vector<std::vector<int>>& ll) {
    flag[vert] = 1;
    int left = cnt + 1;
    for (auto& next : ll[vert]) {
        if (flag[next] == 1) {
            continue;
        }
        cnt = dfs(next, cnt, flag, ans, ll);
    }
    int right = std::max(cnt, left);
    ans[vert] = std::make_pair(left, right);
    return right;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        ll[u].emplace_back(v);
        ll[v].emplace_back(u);
    }

    std::vector<int> flag(N, 0);
    std::vector<std::pair<int, int>> ans(N);
    dfs(0, 0, flag, ans, ll);

    for (auto& pair : ans) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}
