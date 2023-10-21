/**
 * @file grl_1_b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-10-21 22:52:31
 */
#include <bits/stdc++.h>


constexpr int MAX = std::numeric_limits<int>::max();

int main(int argc, char** argv) {
    int v, e, r;
    std::cin >> v >> e >> r;

    std::vector<std::vector<std::pair<int, int>>> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        g[s].push_back(std::make_pair(d, t));
    }

    std::vector<int> dist(v, MAX);
    dist[r] = 0;

    bool flag = false;
    for (int i = 0; i < 2 * v + 1; i++) {
        flag = false;
        for (int j = 0; j < v; j++) {
            if (dist[j] == MAX) {
                continue;
            }
            for (auto&& edge : g[j]) {
                if (dist[j] + edge.first < dist[edge.second]) {
                    dist[edge.second] = dist[j] + edge.first;
                    flag = true;
                }
            }
        }
        if (!flag) {
            break;
        }
    }

    if (flag) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
        for (auto&& d : dist) {
            if (d == MAX) {
                std::cout << "INF" << std::endl;
            } else {
                std::cout << d << std::endl;
            }
        }
    }
}
