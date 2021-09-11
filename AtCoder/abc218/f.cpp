/*
 * f.cpp
 *
 * Create Date : 2021-09-11 22:33:54
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

struct Edge {
    int i;
    int d;
    int s;
};


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<Edge>> ll(N);
    for (int i = 0; i < M; i++) {
        int s, t;
        std::cin >> s >> t;
        s--, t--;
        ll[s].emplace_back(Edge{i, t, s});
    }

    for (int i = 0; i < M; i++) {
        std::queue<Edge> que;
        std::vector<int> ws(N, -1);
        ws[0] = 0;
        for (auto& next : ll[0]) {
            if (next.i != i && ws[next.d] == -1) {
                que.push(next);
                ws[next.d] = ws[0] + 1;
            }
        }
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            for (auto& next : ll[cur.d]) {
                if (next.i != i && ws[next.d] == -1) {
                    que.push(next);
                    ws[next.d] = ws[cur.d] + 1;
                }
            }
        }
        std::cout << ws[N - 1] << std::endl;
    }
}
