/*
 * grl5_a.cpp
 *
 * Create Date : 2020-04-30 23:04:29
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>
#include <queue>


struct Node {
    int idx;
    std::vector<std::pair<int, int>> links;
};


int dfs(int current, int prev, int cost, const std::vector<Node> nodes) {
    if (nodes[current].links.size() == 1 && nodes[current].links[0].first == prev) {
        return cost;
    }
    int max_cost = cost;
    for (auto && link : nodes[current].links) {
        if (link.first == prev) {
            continue;
        }
        max_cost = std::max(max_cost, dfs(link.first, current, cost + link.second, nodes));
    }
    return max_cost;
}


int main() {
    int n;
    std::cin >> n;

    std::vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i].idx = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        std::cin >> s >> t >> w;
        nodes[s].links.emplace_back(std::make_pair(t, w));
        nodes[t].links.emplace_back(std::make_pair(s, w));
    }

    std::queue<Node> que;
    std::vector<int> costs(n, 0), color(n, 0);
    que.push(nodes[0]);
    while (!que.empty()) {
        auto node = que.front();
        color[node.idx] = 1;
        que.pop();

        for (auto link : node.links) {
            if (color[link.first] == 0) {
                que.push(nodes[link.first]);
                costs[link.first] = costs[node.idx] + link.second;
            }
        }
    }

    int max_idx = 0;
    int max = costs[max_idx];
    for (int i = 1; i < n; i++) {
        if (costs[i] > max) {
            max = costs[i];
            max_idx = i;
        }
    }

    que.push(nodes[max_idx]);
    costs = std::vector<int>(n, 0);
    color = std::vector<int>(n, 0);

    while (!que.empty()) {
        auto node = que.front();
        color[node.idx] = 1;
        que.pop();

        for (auto link : node.links) {
            if (color[link.first] == 0) {
                que.push(nodes[link.first]);
                costs[link.first] = costs[node.idx] + link.second;
            }
        }
    }

    max = 0;
    for (int i = 0; i < n; i++) {
        if (costs[i] > max) {
            max = costs[i];
        }
    }

    std::cout << max << std::endl;
}
