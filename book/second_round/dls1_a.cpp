/*
 * ls1_a.cpp
 *
 * Create Date : 2020-04-16 23:34:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>


struct UFT {
    int i;
    UFT* parent = nullptr;
};


int getValue(int x, UFT *n) {
    UFT* parent = &n[x];
    while (parent->parent != nullptr) {
        parent = parent->parent;
    }
    return parent->i;
}


void unit(int x, int y, UFT *n) {
    int px = getValue(x, n);
    int py = getValue(y, n);
    if (px == py) {
        return;
    }
    if (px < py) {
        n[py].parent = &n[px];
    } else {
        n[px].parent = &n[py];
    }
}


void same(int x, int y, UFT *n) {
    int px = getValue(x, n);
    int py = getValue(y, n);
    if (px == py) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}


int main() {
    int n, q;
    std::cin >> n >> q;

    UFT set[n];

    for (int i = 0; i < n; i++) {
        set[i].i = i;
    }
    
    for (int i = 0; i < q; i++) {
        int com, x, y;
        std::cin >> com >> x >> y;
        if (com == 0) {
            unit(x, y, set);
        } else {
            same(x, y, set);
        }
    }
}
