/*
 * b.cpp
 *
 * Create Date : 2021-10-30 21:02:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> cnt(N, 0);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 0; i < N; i++) {
        if (cnt[i] == N - 1) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
}
