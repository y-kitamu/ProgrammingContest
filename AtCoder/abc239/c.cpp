/*
 * c.cpp
 *
 * Create Date : 2022-02-19 21:05:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::vector<std::vector<int>> dxys{{1, 2},   {2, 1},   {-1, 2}, {-2, 1},
                                       {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
    for (auto& d0 : dxys) {
        for (auto& d1 : dxys) {
            if (x1 + d0[0] == x2 + d1[0] && y1 + d0[1] == y2 + d1[1]) {
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
}
