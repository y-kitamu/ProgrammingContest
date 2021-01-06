#include <bits/stdc++.h>


struct Edge {
    int start, end, weight;
};

int main() {
    int v, e, r;
    std::cin >> v >> e >> r;

    std::vector<Edge> edges(e);
    for (int i = 0; i < e; i++) {
        std::cin >> edges[i].start >> edges[i].end >> edges[i].weight;
    }

    int MAX_VAL = 1e9;
    std::vector<int> g(v, MAX_VAL);
    g[r] = 0;
    for (int i = 0; i < v; i++) {
        for (auto edge : edges) {
            if (g[edge.start] != MAX_VAL) {
                g[edge.end] = std::min(g[edge.start] + edge.weight, g[edge.end]);
            }
        }
    }

    bool has_cycle = false;
    for (auto edge : edges) {
        if (g[edge.start] != MAX_VAL) {
            if (g[edge.start] + edge.weight < g[edge.end]) {
                has_cycle = true;
                break;
            }
        }
    }

    if (has_cycle) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    } else {
        for (int i = 0; i < v; i++) {
            if (g[i] == MAX_VAL) {
                std::cout << "INF" << std::endl;
            } else {
                std::cout << g[i] << std::endl;
            }
        }
    }
}
