/*
 * d.cpp
 *
 * Create Date : 2021-10-23 21:13:26
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int M;
    std::cin >> M;

    std::set<std::string> memo;

    std::vector<std::vector<int>> ll(9);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        ll[u].emplace_back(v);
        ll[v].emplace_back(u);
    }

    std::string goal = "123456789";
    std::string start = "999999999";
    for (int i = 0; i < 8; i++) {
        int p;
        std::cin >> p;
        p--;
        start[p] = (char)('1' + i);
    }

    std::queue<std::pair<int, std::string>> que;
    que.push(std::make_pair(0, start));
    while (!que.empty()) {
        auto front = que.front();
        // std::cout << front.first << " , " << front.second << std::endl;
        que.pop();
        if (front.second == goal) {
            std::cout << front.first << std::endl;
            return 0;
        }
        memo.insert(front.second);
        int idx = 0;
        for (; idx < 9; idx++) {
            if (front.second[idx] == '9') {
                break;
            }
        }
        for (auto& next : ll[idx]) {
            std::string str = front.second;
            std::swap(str[idx], str[next]);
            if (memo.find(str) == memo.end()) {
                que.push(std::make_pair(front.first + 1, str));
                memo.insert(str);
            }
        }
    }
    std::cout << -1 << std::endl;
}
