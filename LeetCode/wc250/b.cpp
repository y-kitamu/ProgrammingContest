/*
 * b.cpp
 *
 * Create Date : 2021-07-18 11:38:17
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int addRungs(std::vector<int>& rungs, int dist) {
        int cur = 0;
        int cnt = 0;
        for (int i = 0; i < rungs.size(); i++) {
            cnt += (rungs[i] - cur - 1) / dist;
            cur = rungs[i];
        }
        return cnt;
    }
};


int main() {}
