/*
 * gel_3_a.cpp
 *
 * Create Date : 2020-04-29 23:00:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>
#include <queue>
#include <set>


std::vector<std::vector<int>> link_list;
std::vector<int> parent;
std::vector<int> prenum;
std::vector<int> visited;
std::vector<int> lowest;
int timer = 0;

void dfs(int current, int prev) {
    visited[current] = 1;
    prenum[current] = timer;
    lowest[current] = prenum[current];
    timer++;

    for (auto next : link_list[current]) {
        if (visited[next] == 0) {
            parent[next] = current;
            dfs(next, current);
            lowest[current] = std::min(lowest[current], lowest[next]);
        } else if (next != prev) {
            lowest[current] = std::min(lowest[current], prenum[next]);
        }
    }
}


int main() {
    int V, E;

    std::cin >> V >> E;
    link_list = std::vector<std::vector<int>>(V);
    parent = std::vector<int>(V);
    prenum = std::vector<int>(V);
    visited = std::vector<int>(V, 0);
    lowest = std::vector<int>(V);

    for (int i = 0; i < E; i++) {
        int s, t;
        std::cin >> s >> t;
        link_list[s].emplace_back(t);
        link_list[t].emplace_back(s);
    }

    dfs(0, -1);

    int np = 0;
    std::set<int> ans;
    for (int i = 1; i < V; i++) {
        if (parent[i] == 0) {
            np++;
        }
        if (prenum[parent[i]] <= lowest[i]) {
            ans.insert(i);
        }
    }

    if (np > 1) {
        ans.insert(0);
    }
    for (auto i : ans) {
        std::cout << i << std::endl;
    }
}
