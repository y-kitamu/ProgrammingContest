/*
 * b.cpp
 *
 * Create Date : 2022-04-03 11:38:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        int MAX = 1e9;
        std::vector<int> counts(2e5, MAX);

        for (auto& match : matches) {
            if (counts[match[0]] == MAX) {
                counts[match[0]] = 0;
            }
            if (counts[match[1]] == MAX) {
                counts[match[1]] = 0;
            }
            counts[match[1]]++;
        }

        std::vector<std::vector<int>> ans(2);
        for (int i = 1; i < counts.size(); i++) {
            if (counts[i] == 0) {
                ans[0].emplace_back(i);
            } else if (counts[i] == 1) {
                ans[1].emplace_back(i);
            }
        }
        return ans;
    }
};

int main() {}
