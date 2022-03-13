/*
 * d.cpp
 *
 * Create Date : 2022-03-13 11:57:54
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Edge {
    int src;
    int dst;
    int w;
};

class Solution {
  public:
    long long minimumWeight(int n, std::vector<std::vector<int>>& edges, int src1, int src2, int dest) {
        std::vector<std::vector<Edge>> ll(n);

        for (auto& edge : edges) {
            ll[edge[0]].emplace_back(Edge{edge[0], edge[1], edge[2]});
        }
    }

    long long dfs(int cur, int dst, std::vector<int>& flag, std::vector<std::vector<int>>& edges) {
        if (dst == cur) {
        }
    }

    long long dik(int src, int dst, std::vector<std::vector<int>>& edges) {}
};


int main() {}
