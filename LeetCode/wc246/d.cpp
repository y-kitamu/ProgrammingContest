/*
 * d.cpp
 *
 * Create Date : 2021-06-20 12:09:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> minDifference(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::vector<std::vector<int>> counts(nums.size() + 1, std::vector<int>(100, 0));

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 100; j++) {
                counts[i + 1][j] = counts[i][j];
            }
            counts[i + 1][nums[i] - 1]++;
        }

        std::vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int lhs = queries[i][0];
            int rhs = queries[i][1] + 1;

            std::vector<int> vals;
            for (int j = 0; j < 100; j++) {
                if (counts[rhs][j] - counts[lhs][j] > 0) {
                    vals.emplace_back(j);
                }
            }
            if (vals.size() <= 1) {
                ans[i] = -1;
            } else {
                std::sort(vals.begin(), vals.end());
                int min = 100;
                for (int j = 1; j < vals.size(); j++) {
                    min = std::min(min, vals[j] - vals[j - 1]);
                }
                ans[i] = min;
            }
        }
        return ans;
    }
};

int main() {}
