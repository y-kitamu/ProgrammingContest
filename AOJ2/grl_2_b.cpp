/**
 * @file grl_2_b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-10-22 09:14:43
 */
#include <bits/stdc++.h>


constexpr int MAX = 1e9;

int main(int argc, char** argv) {
    int v, e, r;
    std::cin >> v >> e >> r;

    std::vector<std::vector<int>> graph;
    for (int i = 0; i < e; i++) {
        int s, t, w;
        std::cin >> s >> t >> w;
        graph.emplace_back(std::vector<int>{s, t, w});
    }
}
