#include <bits/stdc++.h>


struct Edge {
    int start, end, weight;
};


int main() {
    int v, e, r;
    std::cin >> v >> e >> r;

    std::vector<std::vector<Edge>> linked_list(v);
    for (int i = 0; i < e; i++) {
        Edge edge;
        std::cin >> edge.start >> edge.end >> edge.weight;
        linked_list[edge.start].emplace_back(edge);
    }

    int MAX_VAL = 1 << 31;
    std::vector<int> min_costs(v, MAX_VAL);
    auto compare = [] (auto &lhs, auto &rhs) {
        return rhs.second < lhs.second;
    };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> que {compare};
    que.push(std::make_pair(r, 0));
    while (!que.empty()) {
        auto pair = que.top();
        que.pop();
        if (min_costs[pair.first] == MAX_VAL) {
            min_costs[pair.first] = pair.second;
            for (auto edge : linked_list[pair.first]) {
                if (min_costs[edge.end] == MAX_VAL) {
                    que.push(std::make_pair(edge.end, min_costs[pair.first] + edge.weight));
                }
            }
        }
    }
    for (auto val : min_costs) {
        if (val == MAX_VAL) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << val << std::endl;
        }
    }
}
