/*
 * a.cpp
 *
 * Create Date : 2021-09-05 11:30:34
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int countQuadruplets(std::vector<int>& nums) {
        int n = nums.size();
        // std::sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                for (int c = b + 1; c < n; c++) {
                    for (int d = c + 1; d < n; d++) {
                        if (nums[a] + nums[b] + nums[c] == nums[d]) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};


int main() {}
