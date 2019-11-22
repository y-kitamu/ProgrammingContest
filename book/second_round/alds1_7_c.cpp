/*
 * alds1_7_c.cpp
 *
 * Create Date : 2019-11-22 23:01:58
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */

#include <iostream>

struct Node {
    int parent = -1;
    int left = -1;
    int right = -1;
};

void preorder(Node * nodes, int idx) {
    if (idx == -1) {
        return;
    }
    std::cout << " " << idx;
    preorder(nodes, nodes[idx].left);
    preorder(nodes, nodes[idx].right);
}

void inorder(Node * nodes, int idx) {
    if (idx == -1) {
        return;
    }
    inorder(nodes, nodes[idx].left);
    std::cout << " " << idx;
    inorder(nodes, nodes[idx].right);
}

void postorder(Node * nodes, int idx) {
    if (idx == -1) {
        return;
    }
    postorder(nodes, nodes[idx].left);
    postorder(nodes, nodes[idx].right);
    std::cout << " " << idx;
}

int main() {
    int n;
    std::cin >> n;

    Node nodes[n];

    for (int i = 0; i < n; i++) {
        int id, left, right;
        std::cin >> id >> left >> right;
        nodes[id].left = left;
        nodes[id].right = right;
        nodes[left].parent = id;
        nodes[right].parent = id;
    }

    int root_idx = -1;
    for (int i = 0; i < n; i++) {
        if (nodes[i].parent == -1) {
            root_idx = i;
            break;
        }
    }

    std::cout << "Preorder" << std::endl;
    preorder(nodes, root_idx);
    std::cout << std::endl;
    std::cout << "Inorder" << std::endl;
    inorder(nodes, root_idx);
    std::cout << std::endl;
    std::cout << "Postorder" << std::endl;
    postorder(nodes, root_idx);
    std::cout << std::endl;
}
