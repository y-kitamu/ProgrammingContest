/*
 * a.cpp
 *
 * Create Date : 2022-04-02 20:57:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int x4, y4;
    if (x1 == x2) {
        x4 = x3;
    } else if (x1 == x3) {
        x4 = x2;
    } else {
        x4 = x1;
    }

    if (y1 == y2) {
        y4 = y3;
    } else if (y1 == y3) {
        y4 = y2;
    } else {
        y4 = y1;
    }
    std::cout << x4 << " " << y4 << std::endl;
}
