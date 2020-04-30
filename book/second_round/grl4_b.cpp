/*
 * grl4_b.cpp
 *
 * Create Date : 2020-04-29 20:58:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>

int V, E;
std::vector<std::vector<int>> link_from;
std::vector<int> flag;

void search(int idx) {
    if (flag[idx] != 0) {
        return;
    }
    for (auto i : link_from[idx]) {
        search(i);
    }

    flag[idx] = 1;
    std::cout << idx << std::endl;
}


int main() {
    std::cin >> V >> E;

    link_from = std::vector<std::vector<int>>(V);
    flag = std::vector<int>(V, 0);
    for (int i = 0; i < E; i++) {
        int s, t;
        std::cin >> s >> t;
        link_from[t].emplace_back(s);
    }

    for (int i = 0; i < V; i++) {
        if (flag[i] == 0) {
            search(i);
        }
    }
}
