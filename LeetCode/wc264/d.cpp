/*
 * d.cpp
 *
 * Create Date : 2021-10-24 12:38:51
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {
        std::vector<int> in_deg(n, 0);
        std::vector<std::vector<int>> ll(n);
        for (auto& rel : relations) {
            rel[0]--, rel[1]--;
            ll[rel[0]].emplace_back(rel[1]);
            in_deg[rel[1]]++;
        }

        auto cmp = [](auto& lhs, auto& rhs) { return lhs.second > rhs.second; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> que{
            cmp};
        for (int i = 0; i < n; i++) {
            if (in_deg[i] == 0) {
                in_deg[i] = 1;
                que.push(std::make_pair(i, time[i]));
            }
        }

        int cur = 0;
        while (!que.empty()) {
            auto pair = que.top();
            que.pop();
            cur = pair.second;
            // std::cout << cur << std::endl;
            in_deg[pair.first]--;
            if (in_deg[pair.first] == 0) {
                for (auto& next : ll[pair.first]) {
                    que.push(std::make_pair(next, cur + time[next]));
                }
            }
        }
        return cur;
    }
};

int main() {}
