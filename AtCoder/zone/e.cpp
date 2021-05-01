#include <bits/stdc++.h>

struct Edge {
    int dst, w;
};


int main() {
    int R, C;
    std::cin >> R >> C;

    auto get_rc = [&C](int r, int c) { return r * C + c; };

    std::vector<std::vector<Edge>> ll(R * C);

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C - 1; j++) {
            int a;
            std::cin >> a;
            int rc0 = get_rc(i - 1, j - 1);
            int rc1 = get_rc(i - 1, j);
            ll[rc0].emplace_back(Edge({rc1, a}));
            ll[rc1].emplace_back(Edge({rc0, a}));
        }
    }

    for (int i = 1; i <= R - 1; i++) {
        for (int j = 1; j <= C; j++) {
            int b;
            std::cin >> b;
            int rc0 = get_rc(i - 1, j - 1);
            int rc1 = get_rc(i, j - 1);
            ll[rc0].emplace_back(Edge{rc1, b});
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int k = 1; k < i; k++) {
            int cost = 1 + k;
            for (int j = 1; j <= C; j++) {
                int rc0 = get_rc(i - 1, j - 1);
                int rc1 = get_rc(i - k - 1, j - 1);
                ll[rc0].emplace_back(Edge({rc1, cost}));
            }
        }
    }

    auto comp = [](auto& lhs, auto& rhs) { return lhs.second > rhs.second; };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{comp};

    for (auto& edge : ll[0]) {
        que.push(std::make_pair(edge.dst, edge.w));
    }

    std::vector<int> cost(R * C, 1e9);
    cost[0] = 0;
    while (!que.empty()) {
        auto top = que.top();
        que.pop();
        if (top.second < cost[top.first]) {
            cost[top.first] = top.second;
            for (auto& edge : ll[top.first]) {
                if (edge.w + cost[top.first] < cost[edge.dst]) {
                    cost[edge.dst] = edge.w + cost[top.first] + 1;
                    que.push(std::make_pair(edge.dst, edge.w + cost[top.first]));
                }
            }
        }
        if (top.first == R * C - 1) {
            break;
        }
    }

    std::cout << cost[R * C - 1] << std::endl;
}
