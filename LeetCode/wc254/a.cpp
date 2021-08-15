/*
 * a.cpp
 *
 * Create Date : 2021-08-15 11:30:21
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int numOfStrings(std::vector<std::string>& patterns, std::string word) {
        int cnt = 0;
        for (auto& pat : patterns) {
            if (word.find(pat) != std::string::npos) {
                cnt++;
            }
        }
        return cnt;
    }
};


int main() {}
