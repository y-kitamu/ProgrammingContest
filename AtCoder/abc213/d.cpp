/*
 * d.cpp
 *
 * Create Date : 2021-08-08 21:22:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

void dfs(int cur, std::vector<int>& map, std::vector<int>& path,
         const std::vector<std::vector<int>>& ll) {
    path.emplace_back(cur);
    map[cur] = 1;

    for (auto& next : ll[cur]) {
        if (map[next] == 1) {
            continue;
        }
        dfs(next, map, path, ll);
        path.emplace_back(cur);
    }
}


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        std::cin >> A >> B;
        A--, B--;
        ll[A].emplace_back(B);
        ll[B].emplace_back(A);
    }

    for (int i = 0; i < N; i++) {
        std::sort(ll[i].begin(), ll[i].end());
    }

    std::vector<int> map(N, 0);
    std::vector<int> path;
    dfs(0, map, path, ll);

    std::cout << path[0] + 1;
    for (int i = 1; i < path.size(); i++) {
        std::cout << " " << path[i] + 1;
    }
    std::cout << std::endl;
}
