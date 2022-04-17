/*
 * d.cpp
 *
 * Create Date : 2022-04-17 12:21:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int longestPath(std::vector<int>& parent, std::string s) {
        ll = std::vector<std::vector<int>>(parent.size());
        str = s;
        for (int i = 1; i < parent.size(); i++) {
            ll[parent[i]].emplace_back(i);
        }
        auto res = count(0);
        return std::max(res.first, res.second);
    }

    std::pair<int, int> count(int cur) {
        auto pair = std::make_pair(1, 1);
        std::vector<int> cnts;
        for (auto& child : ll[cur]) {
            auto res = count(child);
            pair.first = std::max(std::max(res.first, res.second), pair.first);
            if (str[child] != str[cur]) {
                pair.second = std::max(res.second + 1, pair.second);
                cnts.emplace_back(res.second);
            }
        }
        std::sort(cnts.begin(), cnts.end(), std::greater<>());

        if (cnts.size() > 1) {
            pair.first = std::max(cnts[0] + cnts[1] + 1, pair.first);
        }
        // std::cout << cur << ", " << pair.first << ", " << pair.second << std::endl;
        return pair;
    }

    std::vector<std::vector<int>> ll;
    std::string str;
};

int main() {}
