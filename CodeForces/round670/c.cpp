#include <bits/stdc++.h>


struct Node {
    int parent = -1;
    std::vector<int> childs;
    int count = 0;
};


void centroid(std::vector<std::vector<int>> & linked_list) {
    int n = linked_list.size();
    int root = 0;
    std::queue<int> que;
    que.push(root);
    std::vector<Node> nodes(n);
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        for (auto next : linked_list[idx]) {
            int count = 0;
            if (nodes[next].parent == -1 && next != root) {
                nodes[next].parent = idx;
                nodes[idx].childs.emplace_back(next);
                count++;
                que.push(next);
            }
            int parent = idx;
            while (parent != -1) {
                nodes[parent].count += count;
                parent = nodes[parent].parent;
            }
        }
    }

    int max_count = 1e5;
    while (true) {
        int max_idx = -1;
        bool duplicate = false;
        for (auto child : nodes[root].childs) {
            if (max_idx == -1) {
                max_idx = child;
            } else if (nodes[child].count > nodes[max_idx].count) {
                max_idx = child;
                duplicate = false;
            } else if (nodes[child].count == nodes[max_idx].count) {
                duplicate = true;
            }
        }
        if (duplicate || max_count < nodes[max_idx].count) {
            std::cout << 1 << " " << linked_list[0][0] + 1 << std::endl;
            std::cout << 1 << " " << linked_list[0][0] + 1 << std::endl;
            break;
        }

        if (max_count == nodes[max_idx].count) {
            int idx = max_idx;
            while (nodes[idx].childs.size() > 0) {
                idx = nodes[idx].childs[0];
            }
            std::cout << idx + 1 << " " << nodes[idx].parent + 1 << std::endl;
            std::cout << idx + 1 << " " << max_idx << std::endl;
            break;
        }
        max_count = nodes[max_idx].count;
        nodes[root].count = n - nodes[max_idx].count;
        std::cout << max_idx << " , " << nodes[max_idx].count << std::endl;
        nodes[max_idx].count = n;
        root = max_idx;
    }
}


int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::vector<int>> linked_list(n);
        for (int j = 0; j < n - 1; j++) {
            int x, y;
            std::cin >> x >> y;
            x--; y--;
            linked_list[x].emplace_back(y);
            linked_list[y].emplace_back(x);
        }
        centroid(linked_list);
    }
}
