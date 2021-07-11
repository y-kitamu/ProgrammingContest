/*
 * b.cpp
 *
 * Create Date : 2021-07-11 11:33:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int countPalindromicSubsequence(std::string s) {
        std::map<int, std::vector<int>> map;
        for (int i = 0; i < s.length(); i++) {
            map[s[i] - 'a'].emplace_back(i);
        }

        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (map[i].size() < 2) {
                continue;
            }
            if (map[i].size() >= 3) {
                count++;
            }
            int first = map[i][0];
            int last = map[i][map[i].size() - 1];

            for (int j = 0; j < 26; j++) {
                if (i == j || map[j].size() == 0) {
                    continue;
                }
                auto fitr = std::upper_bound(map[j].begin(), map[j].end(), first);
                auto litr = std::upper_bound(map[j].begin(), map[j].end(), last);
                if (fitr != litr) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {}
