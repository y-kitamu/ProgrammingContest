/*
 * grl1_c.cpp
 *
 * Create Date : 2020-04-25 20:22:28
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>
#include <queue>


struct Node {
    Node() {}
    Node (int idx, int value): idx(idx), value(value) {}
    int status = -1;
    int idx;
    int value;
};


struct Line {
    Line() {}
    Line(int next, int weight): next(next), weight(weight) {}

    int next;
    int weight;
};


std::vector<Node> cost(std::vector<std::vector<Line>> link_mat, int idx) {
    auto compare = [](Node *lhs, Node *rhs) { return lhs->value < rhs->value; };
    std::priority_queue<Node *, std::vector<Node *>, decltype(compare)> que { compare };

    std::vector<Node> ds(link_mat.size());
    for (int i = 0; i < link_mat.size(); i++) {
        ds[i].idx = i;
        ds[i].value = 0;
    }

    ds[idx].status = 0;
    que.push(&ds[idx]);
    while (!que.empty()) {
        Node* q = que.top();
        que.pop();

        for (auto &link : link_mat[q->idx]) {
            if (ds[link.next].status == -1 || q->value + link.weight < ds[link.next].value) {
                ds[link.next].status = 0;
                ds[link.next].value = q->value + link.weight;
                que.push(&ds[link.next]);
            }
        }
    }
    return ds;
}



static constexpr long long int  INF = 10000000000;

int main() {
    int V, E;
    std::cin >> V >> E;

    // std::vector<std::vector<Line>> link_list(V);
    std::vector<std::vector<long long int>> costs(V, std::vector<long long int>(V, INF));
    for (int i = 0; i < V; i++) {
        costs[i][i] = 0;
    }

    for (int i = 0; i < E; i++) {
        int s, t, d;
        std::cin >> s >> t >> d;
        // link_list[s].push_back(Line(t, d));
        costs[s][t] = d;
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (costs[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < V; j++) {
                if (costs[k][j] == INF) {
                    continue;
                }
                costs[i][j] = std::min(costs[i][j], costs[i][k] + costs[k][j]);
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (costs[i][i] < 0) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (j) {
                std::cout << " ";
            }
            if (costs[i][j] == INF) {
                std::cout << "INF";
            } else {
                std::cout << costs[i][j];
            }
        }
        std::cout << std::endl;
    }
}
