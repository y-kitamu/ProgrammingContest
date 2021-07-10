/*
 * e.cpp
 *
 * Create Date : 2021-07-10 21:16:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> s(N);
    std::map<std::string, std::vector<int>> head, back;
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];
        head[s[i].substr(0, 3)].emplace_back(i);
        back[s[i].substr(s[i].length() - 3)].emplace_back(i);
    }

    std::vector<int> res(N, -1);  // 0 = win tak, 1 = win aok, 2 = draw
    for (auto& b : back) {
        if (head[b.first].size() == 0) {
            for (auto& idx : b.second) {
                res[idx] = 0;
            }
        }
    }
}
