/*
 * d.cpp
 *
 * Create Date : 2021-07-10 21:07:17
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

void dfs(int idx, int d, std::vector<int>& dist, std::vector<std::vector<int>>& links) {
    dist[idx] = d;
    for (auto& next : links[idx]) {
        if (dist[next] == -1) {
            dfs(next, d + 1, dist, links);
        }
    }
}


int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::vector<int>> links(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        links[a].emplace_back(b);
        links[b].emplace_back(a);
    }

    std::vector<int> dist(N, -1);
    dfs(0, 0, dist, links);

    for (int i = 0; i < Q; i++) {
        int c, d;
        std::cin >> c >> d;
        c--;
        d--;

        if ((dist[c] + dist[d]) % 2 == 0) {
            std::cout << "Town" << std::endl;
        } else {
            std::cout << "Road" << std::endl;
        }
    }
}
