/*
 * a.cpp
 *
 * Create Date : 2021-06-13 11:29:12
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    bool makeEqual(std::vector<std::string>& words) {
        int n = words.size();
        std::vector<int> counts(26, 0);
        for (auto& word : words) {
            for (auto& c : word) {
                counts[c - 'a']++;
            }
        }
        bool flag = true;
        for (auto cnt : counts) {
            flag &= cnt % n == 0;
        }
        return flag;
    }
};


int main() {}
