/*
 * d.cpp
 *
 * Create Date : 2021-07-04 21:10:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Path {
    long long int from;
    long long int dst;
    long long int time;
    long long int cost;
};


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<Path>> link(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        link[a].emplace_back(Path{a, b, c, 0});
    }

    long long int sum = 0;
    auto comp = [](auto& lhs, auto& rhs) {
        if (lhs.from != rhs.from) {
            return lhs.from > rhs.from;
        }
        return lhs.cost > rhs.cost;
    };
    for (int j = 0; j < N; j++) {
        std::priority_queue<Path, std::vector<Path>, decltype(comp)> que{comp};
        std::vector<std::vector<long long int>> cost(
            N, std::vector<long long int>(2, 0));  // 0: current min cost, 1: idx
        for (auto& l : link[j]) {
            cost[l.dst][0] = l.time;
            l.cost = l.time;
            que.push(l);
        }

        while (!que.empty()) {
            auto path = que.top();
            que.pop();
            if (cost[path.dst][0] == 0 || path.cost < cost[path.dst][0]) {
                sum += (path.from - cost[path.dst][1]) * cost[path.dst][0];
                cost[path.dst][0] = path.cost;
                cost[path.dst][1] = path.from;
            }
            for (auto& next : link[path.dst]) {
                if (next.dst == j) {
                    continue;
                }
                next.cost = path.cost + next.time;
                if (cost[next.dst][0] == 0 || next.cost < cost[next.dst][0]) {
                    que.push(next);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (i == j) {
                continue;
            }
            sum += (N - cost[i][1]) * cost[i][0];
        }
        std::cout << sum << std::endl;
    }
    std::cout << sum << std::endl;
}
