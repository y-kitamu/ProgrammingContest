/*
 * f.cpp
 *
 * Create Date : 2022-03-20 21:39:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Node {
    int val;
    int cur;
};


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        ll[u].emplace_back(v);
        ll[v].emplace_back(u);
    }

    std::vector<std::vector<int>> dist(1 << N, std::vector<int>(N, 1e9));
    std::queue<Node> que;
    for (int i = 0; i < N; i++) {
        dist[0][i] = 0;
        dist[1 << i][i] = 1;
        que.push({1 << i, i});
    }

    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        for (auto& next : ll[top.cur]) {
            auto nval = top.val ^ (1 << next);
            if (dist[top.val][top.cur] + 1 < dist[nval][next]) {
                dist[nval][next] = dist[top.val][top.cur] + 1;
                que.push({nval, next});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        int min = dist[i][0];
        for (int j = 1; j < N; j++) {
            min = std::min(min, dist[i][j]);
        }
        ans += min;
    }
    std::cout << ans << std::endl;
}
