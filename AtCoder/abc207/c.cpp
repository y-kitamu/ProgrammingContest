/*
 * c.cpp
 *
 * Create Date : 2021-06-26 21:07:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<long long int>> seg(N, std::vector<long long int>(2));

    for (int i = 0; i < N; i++) {
        int t;
        std::cin >> t >> seg[i][0] >> seg[i][1];
        seg[i][0] *= 2;
        seg[i][1] *= 2;
        if (t == 2) {
            seg[i][1]--;
        } else if (t == 3) {
            seg[i][0]++;
        } else if (t == 4) {
            seg[i][0]++;
            seg[i][1]--;
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (seg[i][1] < seg[j][0] || seg[j][1] < seg[i][0]) {
                continue;
            }
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
