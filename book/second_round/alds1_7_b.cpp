/*
 * alds1_7_b.cpp
 *
 * Create Date : 2019-11-22 22:05:21
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>

struct Node {
    int parent = -1;
    int right = -1;
    int left = -1;
    int sibling = -1;
    int depth = 0;
    int height = 0;
};

int calc_depth(int root_idx, Node * nodes, int depth) {
    nodes[root_idx].depth = depth;
    if (nodes[root_idx].left == -1 && nodes[root_idx].right == -1) {
        nodes[root_idx].height = 0;
        return 0;
    }
    int height = 0;
    if (nodes[root_idx].left != -1) {
        height = calc_depth(nodes[root_idx].left, nodes, depth + 1) + 1;
    }
    if (nodes[root_idx].right != -1) {
        height = std::max(height, calc_depth(nodes[root_idx].right, nodes, depth + 1) + 1);
    }
    nodes[root_idx].height = height;
    return height;
}

int main() {
    int n;
    std::cin >> n;

    Node nodes[n];
    
    for (int _ = 0; _ < n; _++) {
        int i, l, r;
        std::cin >> i >> l >> r;
        nodes[i].left = l;
        nodes[i].right = r;
        nodes[l].parent = i;
        nodes[r].parent = i;
        nodes[l].sibling = r;
        nodes[r].sibling = l;
    }

    int root_idx = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].parent == -1) {
            root_idx = i;
            break;
        }
    }

    calc_depth(root_idx, nodes, 0);

    for (int i = 0; i < n; i++) {
        int sibling = -1;
        if (nodes[i].parent != -1) {
            int sib_l = nodes[nodes[i].parent].left;
            int sib_r = nodes[nodes[i].parent].right;
            sibling = sib_l == i ? sib_r : sib_l;
        }
        int degree = int(nodes[i].left != -1) + int(nodes[i].right != -1);
        std::string type = "internal node";
        if (nodes[i].parent == -1) {
            type = "root";
        } else if (degree == 0) {
            type = "leaf";
        }
        std::cout << "node " << i << ": parent = " << nodes[i].parent
                  << ", sibling = " << sibling
                  << ", degree = " << degree
                  << ", depth = " << nodes[i].depth
                  << ", height = " << nodes[i].height
                  << ", " << type << std::endl;
    }
}
