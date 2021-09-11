/*
 * e.cpp
 *
 * Create Date : 2021-09-11 21:54:12
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Edge {
    long long int i;
    long long int d;
    long long int w;
};


int main() {
    long long int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<Edge>> ll(N);
    std::vector<std::vector<long long int>> es(M, std::vector<long long int>(3));

    long long int max = 0;
    long long int min_idx = 0;
    for (int i = 0; i < M; i++) {
        std::cin >> es[i][0] >> es[i][1] >> es[i][2];
        es[i][0]--;
        es[i][1]--;
        if (es[min_idx][2] > es[i][2]) {
            min_idx = i;
        }
        max = std::max(max, es[i][2]);
        ll[es[i][0]].emplace_back(Edge{i, es[i][1], es[i][2]});
        ll[es[i][1]].emplace_back(Edge{i, es[i][0], es[i][2]});
    }

    if (M == N - 1 || max <= 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    auto comp = [](auto& lhs, auto& rhs) { return lhs.w > rhs.w; };
    std::priority_queue<Edge, std::vector<Edge>, decltype(comp)> que{comp};
    std::vector<int> eflag(M, 0);
    std::vector<int> flag(N, 0);
    flag[es[min_idx][0]] = 1;
    flag[es[min_idx][1]] = 1;
    eflag[min_idx] = 1;

    for (int i = 0; i < 2; i++) {
        for (auto& next : ll[es[min_idx][i]]) {
            if (flag[next.d] == 0) {
                que.push(next);
            } else {
                if (next.w < 0) {
                    eflag[next.i] = 1;
                }
            }
        }
    }

    while (!que.empty()) {
        auto cur = que.top();
        que.pop();
        if (flag[cur.d] == 1) {
            if (cur.w < 0) {
                eflag[cur.i] = 1;
            }
            continue;
        }
        flag[cur.d] = 1;
        eflag[cur.i] = 1;
        for (auto& next : ll[cur.d]) {
            if (flag[next.d] == 0) {
                que.push(next);
            } else if (next.w < 0) {
                eflag[next.i] = 1;
            }
        }
    }

    long long int sum = 0;
    for (int i = 0; i < M; i++) {
        if (eflag[i] == 0) {
            sum += es[i][2];
        }
    }

    std::cout << sum << std::endl;
}
