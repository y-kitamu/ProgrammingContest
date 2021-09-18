/*
 * e.cpp
 *
 * Create Date : 2021-09-18 21:35:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::vector<std::vector<int>> A(4, std::vector<int>(4));

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            std::cin >> A[y][x];
        }
    }

    std::vector<int> roots(16);
    auto find_root = [&roots](auto idx) {
        std::vector<int> update;
        while (roots[idx] != idx) {
            update.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& i : update) {
            roots[i] = idx;
        }
        return idx;
    };

    int cnt = 0;
    for (int i = 0; i < (1 << 16); i++) {
        std::iota(roots.begin(), roots.end(), 0);

        int min_root = 100;
        bool flag = true;
        for (int j = 0; j < 16; j++) {
            int y = j / 4;
            int x = j % 4;

            if (A[y][x] == 1 && !((i >> j) & 1)) {
                flag = false;
                break;
            }

            if ((i >> j) & 1) {
                int root = roots[j];
                if (x > 0 && (i >> (j - 1) & 1)) {
                    root = std::min(root, find_root(j - 1));
                }
                if (y > 0 && (i >> (j - 4) & 1)) {
                    root = std::min(root, find_root(j - 4));
                }
                if (x < 3 && (i >> (j + 1) & 1)) {
                    root = std::min(root, find_root(j + 1));
                }
                if (y < 3 && (i >> (j + 4) & 1)) {
                    root = std::min(root, find_root(j + 4));
                }
                roots[j] = root;
                if (x > 0 && (i >> (j - 1) & 1)) {
                    roots[j - 1] = root;
                }
                if (y > 0 && (i >> (j - 4) & 1)) {
                    roots[j - 4] = root;
                }
                if (x < 3 && (i >> (j + 1) & 1)) {
                    roots[j + 1] = root;
                }
                if (y < 3 && (i >> (j + 4) & 1)) {
                    roots[j + 4] = root;
                }
                min_root = std::min(min_root, root);
            }
        }

        if (flag) {
            for (int j = 0; j < 16; j++) {
                if ((i >> j) & 1) {
                    flag &= min_root == find_root(j);
                }
            }

            if (flag) {
                std::cout << "success" << std::endl;
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}
