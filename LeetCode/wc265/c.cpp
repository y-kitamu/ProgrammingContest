/*
 * c.cpp
 *
 * Create Date : 2021-10-31 11:41:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minimumOperations(std::vector<int>& nums, int start, int goal) {
        int MAX = 2000;
        std::vector<int> cnt(1001, MAX);
        cnt[start] = 0;
        std::queue<int> que;
        que.push(start);
        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            for (auto& val : nums) {
                auto add = top + val;
                auto res = top - val;
                auto xo = top ^ val;
                if (add == goal || res == goal || xo == goal) {
                    return cnt[top] + 1;
                }
                if (0 <= add && add <= 1000 && cnt[add] == MAX) {
                    cnt[add] = cnt[top] + 1;
                    que.push(add);
                }
                if (0 <= res && res <= 1000 && cnt[res] == MAX) {
                    cnt[res] = cnt[top] + 1;
                    que.push(res);
                }
                if (0 <= xo && xo <= 1000 && cnt[xo] == MAX) {
                    cnt[xo] = cnt[top] + 1;
                    que.push(xo);
                }
            }
        }
        return -1;
    }
};


int main() {}
