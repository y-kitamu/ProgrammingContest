/*
 * e.cpp
 *
 * Create Date : 2022-02-05 21:43:48
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::vector<int>> ll(N + 1);
    for (int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        l--;
        ll[l].emplace_back(r);
        ll[r].emplace_back(l);
    }

    std::vector<int> flag(N + 1, 0);
    std::queue<int> que;
    que.push(0);
    flag[0] = 1;
    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        if (top == N) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
        for (auto& next : ll[top]) {
            if (flag[next]) {
                continue;
            }
            if (next == N) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
            que.push(next);
            flag[next] = 1;
        }
    }
    std::cout << "No" << std::endl;
}
