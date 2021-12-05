/*
 * a.cpp
 *
 * Create Date : 2021-12-05 11:29:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) {
        std::vector<int> cnts(10, 0);
        for (auto& val : digits) {
            cnts[val]++;
        }
        std::vector<int> ans;
        for (int i = 100; i <= 999; i += 2) {
            std::vector<int> cnt(10, 0);
            cnt[i / 100]++;
            cnt[(i % 100) / 10]++;
            cnt[i % 10]++;
            bool flag = true;
            for (int i = 0; i < 10; i++) {
                flag &= cnt[i] <= cnts[i];
            }
            if (flag) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};


int main() {}
