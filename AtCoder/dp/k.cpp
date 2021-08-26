/*
 * k.cpp
 *
 * Create Date : 2021-08-26 21:17:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    int min = 1e9;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        min = std::min(a[i], min);
    }

    std::vector<int> ans(K + 1, -1);
    for (int i = 0; i < min; i++) {
        ans[i] = 0;
    }
    for (int i = 0; i <= K; i++) {
        bool is_win = false;
        for (int j = 0; j < N; j++) {
            if (i - a[j] >= 0) {
                if (ans[i - a[j]] == 0) {
                    is_win = true;
                }
            }
        }
        ans[i] = (int)is_win;
        // std::cout << ans[i] << " ";
    }
    // std::cout << std::endl;

    if (ans[K] % 2 == 0) {
        std::cout << "Second" << std::endl;
    } else {
        std::cout << "First" << std::endl;
    }
}
