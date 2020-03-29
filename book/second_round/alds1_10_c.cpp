/*
 * alds1_10_c.cpp
 *
 * Create Date : 2020-03-29 13:27:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <string>

static int lc[1000][1000];
static std::string X, Y;

int count(int idx_x, int idx_y) {
    if (lc[idx_x][idx_y] != -1) {
        return lc[idx_x][idx_y];
    }

    int maximum = 0;
    
    if (X[idx_x] == Y[idx_y]) {
        if (idx_x > 0 && idx_y > 0) {
            maximum = std::max(maximum, count(idx_x - 1, idx_y - 1));
        }
        lc[idx_x][idx_y] = maximum + 1;
    } else {
        if (idx_x > 0) {
            maximum = std::max(maximum, count(idx_x - 1, idx_y));
        }
        if (idx_y > 0) {
            maximum = std::max(maximum, count(idx_x, idx_y - 1));
        }
        lc[idx_x][idx_y] = maximum;
    }
    return lc[idx_x][idx_y];
}

int LongestCommon() {
    for (int i = 0; i < X.length(); i++) {
        for (int j = 0; j < Y.length(); j++) {
            lc[i][j] = -1;
        }
    }
    return count(X.length() - 1, Y.length() - 1);
}

int main() {
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> X >> Y;
        std::cout << LongestCommon() << std::endl;
    }
}
