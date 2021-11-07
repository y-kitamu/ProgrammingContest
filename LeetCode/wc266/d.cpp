/*
 * d.cpp
 *
 * Create Date : 2021-11-07 12:02:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int zero_max = 0;
    std::vector<std::vector<std::pair<int, int>>> ll;
    std::vector<int> values;

    int maximalPathQuality(std::vector<int>& values, std::vector<std::vector<int>>& edges, int maxTime) {
        int n = values.size();
        ll = std::vector<std::vector<std::pair<int, int>>>(n);
        this->values = values;
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            ll[u].emplace_back(std::make_pair(v, t));
            ll[v].emplace_back(std::make_pair(u, t));
        }
        std::vector<bool> visited(n, false);
        dfs(0, 0, 0, maxTime, visited);
        return zero_max;
    }

    void dfs(int val, int cur_node, int cur_time, int maxTime, std::vector<bool>& visited) {
        if (cur_time > maxTime) {
            return;
        }
        bool before = visited[cur_node];
        if (!visited[cur_node]) {
            val += values[cur_node];
            visited[cur_node] = true;
        }
        if (cur_node == 0) {
            zero_max = std::max(zero_max, val);
        }
        for (auto& next : ll[cur_node]) {
            dfs(val, next.first, cur_time + next.second, maxTime, visited);
        }
        visited[cur_node] = before;
    }
};


int main() {}
