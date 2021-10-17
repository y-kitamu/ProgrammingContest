/*
 * d.cpp
 *
 * Create Date : 2021-10-17 21:14:08
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::set<int>> ll(N);
    std::vector<int> in_cnt(N, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        if (ll[a].find(b) == ll[a].end()) {
            ll[a].insert(b);
            in_cnt[b]++;
        }
    }

    std::vector<int> flag(N, 0);
    std::priority_queue<int, std::vector<int>, std::greater<>> que{std::greater<>()};
    for (int i = 0; i < N; i++) {
        if (in_cnt[i] == 0) {
            in_cnt[i] = 1;
            que.push(i);
        }
    }

    std::vector<int> ans(N, 0);
    int idx = 0;
    while (!que.empty()) {
        auto top = que.top();
        // std::cout << top << std::endl;
        que.pop();
        if (flag[top] > in_cnt[top]) {
            std::cout << -1 << std::endl;
            return 0;
        }
        flag[top]++;
        if (flag[top] == in_cnt[top]) {
            ans[idx++] = top;
            for (auto& next : ll[top]) {
                que.push(next);
            }
        }
    }
    if (idx < N) {
        std::cout << -1 << std::endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        std::cout << ans[i] + 1;
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
