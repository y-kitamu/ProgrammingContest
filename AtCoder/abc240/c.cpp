/*
 * c.cpp
 *
 * Create Date : 2022-02-20 21:03:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> pos(X + 1, 0);
    pos[0] = 1;
    for (int i = 0; i < N; i++) {
        std::vector<int> next(X + 1, 0);
        int a, b;
        std::cin >> a >> b;
        for (int j = 0; j < X; j++) {
            if (pos[j] > 0) {
                if (a + j <= X) {
                    next[a + j]++;
                }
                if (b + j <= X) {
                    next[b + j]++;
                }
            }
        }
        pos = next;
    }

    if (pos[X] > 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
