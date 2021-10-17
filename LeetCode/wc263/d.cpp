/*
 * d.cpp
 *
 * Create Date : 2021-10-17 12:01:00
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change) {
        std::vector<std::vector<int>> ll(n);
        for (auto& edge : edges) {
            edge[0]--;
            edge[1]--;
            ll[edge[0]].emplace_back(edge[1]);
            ll[edge[1]].emplace_back(edge[0]);
        }

        auto cmp = [](auto& lhs, auto& rhs) { return lhs.second > rhs.second; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> que{
            cmp};
        que.push(std::make_pair(0, 0));
        std::vector<int> cnt(n, 0), arrive(n, -1), leave(n, -1);
        while (!que.empty()) {
            auto cur = que.top();
            que.pop();
            // std::cout << cur.first << ", " << cur.second << std::endl;

            if (arrive[cur.first] < cur.second) {
                arrive[cur.first] = cur.second;
                if (cur.first == n - 1 && cnt[n - 1] == 1) {
                    break;
                }

                auto l = cur.second;
                int div = cur.second / change;
                if (div % 2 == 1) {
                    l = (div + 1) * change;
                }
                if (leave[cur.first] < l) {
                    for (auto& next : ll[cur.first]) {
                        if (cnt[next] < 2) {
                            que.push(std::make_pair(next, l + time));
                        }
                    }
                    leave[cur.first] = l;
                    cnt[cur.first]++;
                }
            }
        }
        return arrive[n - 1];
    }
};


int main() {}
