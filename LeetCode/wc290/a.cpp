/*
 * a.cpp
 *
 * Create Date : 2022-04-24 11:27:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> intersection(std::vector<std::vector<int>>& nums) {
        std::vector<int> cnts(2000, 0);

        for (auto& vec : nums) {
            for (auto& val : vec) {
                cnts[val]++;
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < cnts.size(); i++) {
            if (cnts[i] == nums.size()) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main() {}
