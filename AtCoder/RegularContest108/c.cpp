#include <bits/stdc++.h>


struct Node {
    int idx;
    std::map<int, std::vector<int>> vecs;
    int number = -1;
};


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<Node> nodes(N);

    for (int i = 0; i < N; i++) {
        nodes[i].idx = i;
    }

    for (int i = 0; i < M; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        u--; v--;
        nodes[u].vecs[c].emplace_back(v);
        nodes[v].vecs[c].emplace_back(u);
    }

    std::sort(nodes.begin(), nodes.end(), [] (auto &lhs, auto &rhs) {
        return lhs.vecs.size() < rhs.vecs.size();
    });

    std::vector<int> roots(N);
    for (int i = 0; i < N; i++) {
        roots[i] = i;
    }

    auto find_root = [&roots] (int idx) {
        std::vector<int> indices;
        while (idx != roots[idx]) {
            indices.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto val : indices) {
            roots[val] = idx;
        }
        return idx;
    };

    for (int i = 0; i < N; i++) {
        int r0 = find_root(i);
        for (auto pair : nodes[i].vecs) {
            int r1 = find_root(pair.first);
            if (r0 == r1) {
                continue;
            }
            bool duplicat = false;
            for (auto val : pair.second) {
                if (nodes[val].number == i) {
                    duplicat = true;
                }
            }
            if (duplicat) {
                continue;
            }
            nodes[i].number = i;
        }
    }

    int gtr = find_root(0);
    for (int i = 1; i < N; i++) {
        if (gtr != find_root(i)) {
            std::cout << "No" << std::endl;
        }
    }

    std::sort(nodes.begin(), nodes.end(), [] (auto &lhs, auto &rhs) {
        return lhs.idx < rhs.idx;
    });

    for (auto node : nodes) {
        std::cout << node.number << std::endl;
    }
}
