/**
 * @file grl_2_a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2023-10-22 08:48:19
 */
#include <bits/stdc++.h>


int main(int argc, char** argv) {
    int v, e;
    std::cin >> v >> e;

    if (e == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int min_s, min_t, min_d = 1000000000;
    std::vector<std::vector<std::pair<int, int>>> graph(v);
    for (int i = 0; i < e; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        graph[s].emplace_back(std::make_pair(d, t));
        graph[t].emplace_back(std::make_pair(d, s));

        if (d < min_d) {
            min_d = d;
            min_s = s;
            min_t = t;
        }
    }

    int cost = 0;
    std::vector<int> flag(v, 0);
    flag[min_s] = 1;
    flag[min_t] = 1;
    cost += min_d;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        que;

    for (auto&& edge : graph[min_s]) {
        if (flag[edge.second] == 0) {
            que.push(edge);
        }
    }
    for (auto&& edge : graph[min_t]) {
        if (flag[edge.second] == 0) {
            que.push(edge);
        }
    }

    while (!que.empty()) {
        auto edge = que.top();
        que.pop();
        if (flag[edge.second] == 0) {
            cost += edge.first;
            flag[edge.second] = 1;
            for (auto&& next : graph[edge.second]) {
                if (flag[next.second] == 0) {
                    que.push(next);
                }
            }
        }
    }

    std::cout << cost << std::endl;
}
