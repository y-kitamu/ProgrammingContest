/*
 * dls2_c.cpp
 *
 * Create Date : 2020-04-21 22:52:10
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>


struct Node {
    int idx;
    std::vector<int> x = std::vector<int>(2);
    Node* left = nullptr;
    Node* right = nullptr;
};


Node* kdtree(std::vector<Node>& nodes, int start, int end, int depth) {
    if (start == end) {
        return nullptr;
    }
    int axis = depth % 2;
    std::sort(nodes.begin() + start, nodes.begin() + end,
              [&axis](auto &lhs, auto &rhs) {return lhs.x[axis] < rhs.x[axis];});
    int center = (start + end) / 2;
    nodes[center].left = kdtree(nodes, start, center, depth + 1);
    nodes[center].right = kdtree(nodes, center + 1, end, depth + 1);
    return &nodes[center];
}


std::vector<int> search(Node * node, std::vector<int>& sxy, std::vector<int>& txy, int depth) {
    if (node == nullptr) {
        return std::vector<int>();
    }

    std::vector<int> indices;
    if (sxy[0] <= node->x[0] && node->x[0] <= txy[0] &&
        sxy[1] <= node->x[1] && node->x[1] <= txy[1]) {
        indices.emplace_back(node->idx);
    }

    int axis = depth % 2;
    int val = node->x[axis];
    if (sxy[axis] <= val) {
        auto ids = search(node->left, sxy, txy, depth + 1);
        indices.insert(indices.begin(), ids.begin(), ids.end());
    }
    if (val <= txy[axis]) {
        auto ids = search(node->right, sxy, txy, depth + 1);
        indices.insert(indices.begin(), ids.begin(), ids.end());
    }

    return indices;
}


int main() {
    int n;
    std::cin >> n;

    std::vector<Node> nodes(n, Node());
    for (int i = 0; i < n; i++) {
        nodes[i].idx = i;
        scanf("%d %d", &nodes[i].x[0], &nodes[i].x[1]);
    }
    Node* root = kdtree(nodes, 0, n, 0);

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::vector<int> sxy(2), txy(2);
        scanf("%d %d %d %d", &sxy[0], &txy[0], &sxy[1], &txy[1]);
        auto indices = search(root, sxy, txy, 0);
        sort(indices.begin(), indices.end());
        for (auto && idx : indices) {
            printf("%d\n", idx);
        }
        printf("\n");
    }
}
