#include <iostream>
#include <vector>
#include <utility>
#include <tuple>


class Tree {
  public:
    
    void add(int parent, int child, int val) {
        tree.push_back(std::make_tuple(parent, child, val));

        int idx = tree.size() - 1;
        while (idx > 0) {
            if (std::get<2>(tree[(idx - 1) / 2]) > std::get<2>(tree[idx])) {
                std::swap(tree[(idx - 1) / 2], tree[idx]);
                idx = (idx - 1) / 2;
            } else {
                break;
            }
        }
    }

    std::tuple<int, int, int> pop() {
        std::tuple<int, int, int> top = tree[0];

        tree[0] = tree[tree.size() - 1];
        tree.erase(tree.begin() + tree.size() - 1);

        int idx = 0;
        while (idx < (int)tree.size()) {
            int l = idx * 2 + 1;
            int r = idx * 2 + 2;
            int min_idx;

            if (l < (int)tree.size() && std::get<2>(tree[idx]) > std::get<2>(tree[l])) min_idx = l;
            else min_idx = idx;

            if (r < (int)tree.size() && std::get<2>(tree[min_idx]) > std::get<2>(tree[r])) min_idx = r;

            if (min_idx != idx) {
                std::swap(tree[min_idx], tree[idx]);
                idx = min_idx;
            } else {
                break;
            }
        }

        return top;
    }

    bool is_not_empty() {
        return tree.size();
    }

    std::vector<std::tuple<int, int, int>> tree;
};



int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> paths(n);

    for (int i = 0; i < n; i++) {
        int u, k;
        std::cin >> u >> k;
        std::vector<std::pair<int, int>> path(k);
        
        for (int j = 0; j < k; j++) {
            int v, c;
            std::cin >> v >> c;
            path[j] = std::make_pair(v, c);
        }
        paths[u] = path;
    }

    Tree tree = Tree();
    std::vector<int> weight(n, 500000);

    weight[0] = 0;
    for (auto && path : paths[0]) {
        tree.add(0, path.first, path.second);
    }

    while (tree.is_not_empty()) {
        std::tuple<int, int, int> path = tree.pop();
        int parent = std::get<0>(path);
        int child = std::get<1>(path);
        int val = std::get<2>(path);

        if (weight[parent] + val < weight[child]) {
            weight[child] = weight[parent] + val;

            for (auto && p : paths[child]) {
                tree.add(child, p.first, p.second);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << i << " " << weight[i] << std::endl;
    }
}
