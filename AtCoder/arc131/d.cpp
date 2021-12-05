/*
 * d.cpp
 *
 * Create Date : 2021-12-05 22:39:07
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M, D;
    std::cin >> N >> M >> D;
    std::vector<long long int> r(M + 1), s(M + 1, 0);
    for (int i = 0; i <= M; i++) {
        std::cin >> r[i];
    }
    for (int i = 0; i < M; i++) {
        std::cin >> s[i];
    }

    auto comp = [](auto& lhs, auto& rhs) { return lhs.firs > rhs.first; };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{comp};

    long long int sum = s[0];
    que.push(std::make_pair(r[1], s[0] - s[1]));
    long long int idx = 0;
    long long int cur = 0;
    for (int i = 1; i < N; i++) {
        cur += D;
        while (idx <= M && cur > r[idx]) {
            idx++;
        }
        if (idx == M + 1) {
            break;
        }
        sum += s[idx];
        que.push(std::make_pair(r[idx + 1] - cur, s[idx] - s[idx - 1]));
    }
}
