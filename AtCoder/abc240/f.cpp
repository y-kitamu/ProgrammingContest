/*
 * f.cpp
 *
 * Create Date : 2022-02-20 21:49:43
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;

    std::vector<long long int> ans(T, -5e18);
    for (int i = 0; i < T; i++) {
        int N, M;
        std::cin >> N >> M;
        long long int sum = 0;
        long long int offset = 0;

        for (int j = 0; j < N; j++) {
            long long int x, y;
            std::cin >> x >> y;
            if (x < 0) {
                long long int max = sum + offset + x;
                ans[i] = std::max(ans[i], max);
            }

            if (x < 0 && offset > 0 && offset + y * x < 0) {
                long long int idx = std::abs(offset / x);
                long long int max = sum + x * idx * (idx + 1) / 2 + offset * idx;
                ans[i] = std::max(max, ans[i]);
            }

            sum += x * y * (y + 1) / 2 + offset * y;
            ans[i] = std::max(sum, ans[i]);
            offset += x * y;
        }
    }

    for (auto& val : ans) {
        std::cout << val << std::endl;
    }
}
