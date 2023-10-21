/**
 * @file grl_1_a.cpp
 * @brief
 * @date 2023-10-21 22:24:38
 */
#include <bits/stdc++.h>


int main(int argc, char** argv) {
    int v, e, r;
    std::cin >> v >> e >> r;

    std::vector<std::vector<std::pair<int, int>>> g(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        g[s].push_back(std::make_pair(d, t));
        // g[t].push_back(std::make_pair(d, s));
    }

    std::vector<int> dist(v, std::numeric_limits<int>::max());
    dist[r] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        que;


    que.push(std::make_pair(0, r));
    while (!que.empty()) {
        auto node = que.top();
        que.pop();
        if (dist[node.second] < node.first) {
            continue;
        }
        dist[node.second] = node.first;

        for (auto&& next : g[node.second]) {
            if (next.first + node.first < dist[next.second]) {
                que.push(std::make_pair(node.first + next.first, next.second));
            }
        }
    }

    for (auto&& d : dist) {
        if (d == std::numeric_limits<int>::max()) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << d << std::endl;
        }
    }
}
