/*
 * c.cpp
 *
 * Create Date : 2021-08-23 21:58:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> act(N, std::vector<int>(3));
    for (int i = 0; i < N; i++) {
        std::cin >> act[i][0] >> act[i][1] >> act[i][2];
    }

    std::vector<int> cur(3, 0), next(3, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            int j0 = (j + 1) % 3;
            int j1 = (j + 2) % 3;
            next[j] = std::max(cur[j0] + act[i][j], cur[j1] + act[i][j]);
        }
        cur = next;
    }
    std::sort(cur.begin(), cur.end());
    std::cout << cur[cur.size() - 1] << std::endl;
}
