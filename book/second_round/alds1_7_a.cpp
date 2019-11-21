/*
 * alds1_7_a.cpp
 *
 * Create Date : 2019-11-21 22:33:18
 * Copyright (c) 2019 Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


struct Node {
    int parent = -1;
    int child_num;
    int * children;
};

int main() {
    int n;
    std::cin >> n;

    Node nodes[n];

    for (int i = 0; i < n; i++) {
        int id, k;
        std::cin >> id >> k;
        nodes[id].children = new int[k];
        nodes[id].child_num = k;
        for (int j = 0; j < k; j++) {
            int idx;
            std::cin >> idx;
            nodes[id].children[j] = idx;
            nodes[idx].parent = id;
        }
    }

    for (int i = 0; i < n; i++) {
        int depth = 0;
        Node n = nodes[i];
        while (n.parent != -1) {
            depth++;
            n = nodes[n.parent];
        }

        std::string type = "internal node";
        if (nodes[i].parent == -1) {
            type = "root";
        } else if (nodes[i].child_num == 0) {
            type = "leaf";
        }
        
        std::cout << "node " << i << ": parent = " << nodes[i].parent
                  << ", depth = " << depth
                  << ", " << type << ", [";

        for (int k = 0; k < nodes[i].child_num - 1; k++) {
            std::cout << nodes[i].children[k] << ", ";
        }
        if (nodes[i].child_num > 0) {
            std::cout << nodes[i].children[nodes[i].child_num - 1];
        }
        std::cout << "]" << std::endl;
    }
}
