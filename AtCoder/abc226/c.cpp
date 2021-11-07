/*
 * c.cpp
 *
 * Create Date : 2021-11-07 21:06:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<long long int> time(N);
    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < N; i++) {
        int k;
        std::cin >> time[i] >> k;
        for (int j = 0; j < k; j++) {
            int a;
            std::cin >> a;
            a--;
            ll[i].emplace_back(a);
        }
    }

    long long int sum = 0;
    std::vector<bool> flag(N, false);
    std::queue<int> que;
    que.push(N - 1);
    while (!que.empty()) {
        auto top = que.front();
        // std::cout << top << std::endl;
        que.pop();
        if (!flag[top]) {
            sum += time[top];
            flag[top] = true;
        }
        for (auto& next : ll[top]) {
            if (!flag[next]) {
                que.push(next);
                sum += time[next];
                flag[next] = true;
            }
        }
    }
    std::cout << sum << std::endl;
}
