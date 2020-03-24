/*
 * alds1_8_b.cpp
 *
 * Create Date : 2020-03-24 22:24:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>

struct Node {
    Node(int key): key(key) {}
    Node *left=nullptr, *right=nullptr, *parent=nullptr;
    int key;
};


void insert(Node * &root, int k) {
    Node *y = nullptr;
    Node *x = root;
    while (x != nullptr) {
        y = x;
        if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    Node * z = new Node(k);
    z->parent = y;
    if (y == nullptr) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void find(Node * root, int k) {
    if (root == nullptr) {
        std::cout << "no" << std::endl;
        return;
    }
    if (root->key == k) {
        std::cout << "yes" << std::endl;
        return;
    }
    if (k < root->key) {
        find(root->left, k);
    } else {
        find(root->right, k);
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
    
    Node * root = nullptr;

    for (int i = 0; i < m; i++) {
        std::string command;
        std::cin >> command;
        if (command == "insert") {
            int k;
            std::cin >> k;
            insert(root, k);
        } else if (command == "find") {
            int k;
            std::cin >> k;
            find(root, k);
        } else {
            print_lef(root);
            std::cout << std::endl;
            print_mid(root);
            std::cout << std::endl;
        }
    }
}
