/*
 * alds1_8_a.cpp
 *
 * Create Date : 2020-03-23 22:39:17
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>

struct Node {
    Node(int key): key(key) {}
    Node *left=nullptr, *right=nullptr, *parent=nullptr;
    int key;
};

struct Tree {
    Node *root=nullptr;
};

void insert(Tree* T, Node *z) {
    Node *y = nullptr;
    Node *x = T->root;
    while (x != nullptr) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y == nullptr) {
        T->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void print_lef(Node * n) {
    if (n->left != nullptr) {
        print_lef(n->left);
    }
    std::cout << " " << n->key;
    if (n->right != nullptr) {
        print_lef(n->right);
    }
}

void print_mid(Node *n) {
    std::cout << " " << n->key;
    if (n->left != nullptr) {
        print_mid(n->left);
    }
    if (n->right != nullptr) {
        print_mid(n->right);
    }
}


int main(int argc, char ** argv) {
    int m;
    std::cin >> m;

    Tree t = Tree();
    Node *nodes[m];
    for (int i = 0; i < m; i++) {
        std::string command;
        std::cin >> command;
        if (command == "insert") {
            int k;
            std::cin >> k;
            nodes[i] = new Node(k);
            insert(&t, nodes[i]);
        } else {
            print_lef(t.root);
            std::cout << std::endl;
            print_mid(t.root);
            std::cout << std::endl;
        }
    }
}
