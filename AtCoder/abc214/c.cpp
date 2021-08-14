/*
 * c.cpp
 *
 * Create Date : 2021-08-14 21:04:32
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> S(N);

    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    auto comp = [](auto lhs, auto rhs) { return lhs.second > rhs.second; };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{comp};
    for (int i = 0; i < N; i++) {
        int t;
        std::cin >> t;
        que.push(std::make_pair(i, t));
    }

    std::vector<int> ans(N, -1);
    int cnt = 0;
    while (!que.empty()) {
        auto front = que.top();
        que.pop();
        if (ans[front.first] != -1) {
            continue;
        }
        ans[front.first] = front.second;
        cnt++;
        if (cnt == N) {
            break;
        }

        int next = (front.first + 1) % N;
        int time = front.second + S[front.first];
        if (ans[next] == -1 || time < ans[next]) {
            que.push(std::make_pair(next, time));
        }
    }
    for (auto& val : ans) {
        std::cout << val << std::endl;
    }
}
