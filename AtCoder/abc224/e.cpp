/*
 * e.cpp
 *
 * Create Date : 2021-10-23 21:40:13
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Node {
    int idx;
    int row;
    int col;
    int val;
    int cnt;
};


int main() {
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<std::vector<std::shared_ptr<Node>>> rows(H), cols(W);
    for (int i = 0; i < N; i++) {
        int r, c, a;
        std::cin >> r >> c >> a;
        r--, c--;
        std::shared_ptr<Node> node(new Node{i, r, c, a, 1});
        rows[r].emplace_back(node);
        rows[c].emplace_back(node);
    }


    auto comp = [](auto& lhs, auto& rhs) { return rhs->val > lhs->val; };
    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < H; i++) {
        std::sort(rows[i].begin(), rows[i].end(), comp);
    }
    for (int i = 0; i < W; i++) {
        std::sort(cols[i].begin(), cols[i].end(), comp);
    }

    std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, decltype(comp)> que{
        comp};

    for (int i = 0; i < H; i++) {
        int col = rows[i][0]->col;
        if (cols[col][0]->idx == rows[i][0]->idx) {
            que.push(rows[i][0]);
        }
    }

    std::vector<int> counts(N, 0);
    while (que.empty()) {
    }
}
