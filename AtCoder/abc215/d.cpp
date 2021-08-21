/*
 * d.cpp
 *
 * Create Date : 2021-08-21 21:38:56
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> gcds(1e5 + 1, 0);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        for (int j = 2; j < std::sqrt(a) + 1; j++) {
            while (a % j == 0) {
                gcds[j] = 1;
                a /= j;
            }
        }
        if (a > 1) {
            gcds[a] = 1;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= M; i++) {
        if (gcds[i] == 0) {
            cnt++;
            continue;
        }
        if (gcds[i] == 1) {
            for (int j = i + i; j <= M; j += i) {
                gcds[j] = 2;
            }
        }
    }

    std::cout << cnt << std::endl;
    for (int i = 1; i <= M; i++) {
        if (gcds[i] == 0) {
            std::cout << i << std::endl;
        }
    }
}
