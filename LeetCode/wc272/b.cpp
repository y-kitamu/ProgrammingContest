/*
 * b.cpp
 *
 * Create Date : 2021-12-19 11:32:51
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::string addSpaces(std::string s, std::vector<int>& spaces) {
        std::string ans;
        ans.reserve(s.length() + spaces.size());

        int si = 0;
        for (int i = 0; i < s.length(); i++) {
            if (si < spaces.size() && spaces[si] == i) {
                ans.push_back(' ');
                si++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main() {}
