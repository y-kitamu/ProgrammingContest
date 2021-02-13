#include <bits/stdc++.h>


constexpr int INF = 1e9;


struct Node {
    Node() {}
    Node(int idx) : idx(idx) {}
    int idx, depth;
    std::vector<int> childs = {};
    std::vector<int> min_depths = {};

    void sort_index() {
        if (childs.size() <= 1) {
            return;
        }
        std::vector<int> indices(childs.size());
        std::iota(indices.begin(), indices.end(), 0);
        auto depths = this->min_depths;
        std::stable_sort(indices.begin(), indices.end(),
                         [&depths](auto &lhs, auto &rhs) { return depths[lhs] < depths[rhs]; });

        std::vector<int> new_c(childs.size()), new_d(depths.size());
        for (int i = 0; i < childs.size(); i++) {
            new_c[i] = childs[indices[i]];
            new_d[i] = depths[indices[i]];
        }
        childs = new_c;
        min_depths = new_d;
    }
};


int dfs(int idx, int d, std::vector<Node> &nodes) {
    nodes[idx].depth = d;
    if (nodes[idx].childs.size() == 0) {
        return d;
    }
    int min_depth = INF;
    for (int i = 0; i < nodes[idx].childs.size(); i++) {
        int next = nodes[idx].childs[i];
        int depth = dfs(next, d + 1, nodes);
        nodes[idx].min_depths.emplace_back(depth);
        min_depth = std::min(depth, min_depth);
    }
    return min_depth;
}


void eulerTour(int idx, int &cnt, std::vector<Node> &nodes, std::vector<int> &counts) {
    if (counts[idx] == INF) {
        counts[idx] = cnt;
        cnt++;
    }

    for (int i = 0; i < nodes[idx].childs.size(); i++) {
        int next = nodes[idx].childs[i];
        cnt++;
        eulerTour(next, cnt, nodes, counts);
    }
    cnt++;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<Node> nodes(n);
    nodes[0] = Node(0);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        p--;
        nodes[p].childs.emplace_back(i);
    }

    dfs(0, 0, nodes);
    for (int i = 0; i < n - 1; i++) {
        nodes[i].sort_index();
    }

    std::vector<int> counts(n, INF);
    int cnt = 0;
    eulerTour(0, cnt, nodes, counts);
    int coin = 0;
    for (int i = 0; i < n; i++) {
        if (counts[i] % 2 == 0) {
            coin++;
        }
    }

    std::cout << coin << std::endl;
}
