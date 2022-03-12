/*
 * e.cpp
 *
 * Create Date : 2022-03-12 21:22:14
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

struct Edge {
    int src;
    int dst;
    long long int w;
};


void warshall_floyd(int n, std::vector<std::vector<long long int>>& d) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                d[j][k] = std::min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<Edge> edges(M);
    std::vector<std::vector<long long int>> d(N, std::vector<long long int>(N, 1e18));
    for (int i = 0; i < N; i++) {
        d[i][i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--;
        edges[i] = Edge{a, b, c};
        d[a][b] = c;
        d[b][a] = c;
    }
    warshall_floyd(N, d);

    int cnt = 0;
    for (int i = 0; i < M; i++) {
        auto e = edges[i];
        int src = e.src;
        int dst = e.dst;
        if (e.w > d[src][dst]) {
            cnt++;
        } else if (e.w == d[src][dst]) {
            for (int j = 0; j < N; j++) {
                if (j == src || j == dst) {
                    continue;
                }
                if (d[src][dst] == d[src][j] + d[j][dst]) {
                    cnt++;
                    break;
                }
            }
        }
    }
    std::cout << cnt << std::endl;
}
