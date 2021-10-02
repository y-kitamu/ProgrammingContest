/*
 * d.cpp
 *
 * Create Date : 2021-10-02 21:18:46
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::map<int, int> map;
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        if (map.find(a) == map.end()) {
            map[a] = 1;
        } else {
            map[a]++;
        }
        if (map.find(a + b) == map.end()) {
            map[a + b] = -1;
        } else {
            map[a + b]--;
        }
    }

    auto comp = [](auto& lhs, auto& rhs) { return lhs.first > rhs.first; };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{comp};
    for (auto& pair : map) {
        que.push(pair);
    }

    std::vector<int> cnts(N, 0);
    int num = 0;
    int prev = 1;
    while (!que.empty()) {
        auto top = que.top();
        que.pop();
        if (num > 0) {
            cnts[num - 1] += top.first - prev;
        }
        num += top.second;
        prev = top.first;
    }

    for (int i = 0; i < N; i++) {
        std::cout << cnts[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
