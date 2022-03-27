/*
 * b.cpp
 *
 * Create Date : 2022-03-27 11:33:48
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minDeletion(std::vector<int>& nums) {
        int cur_idx = 0;
        int cur_val = -1;
        for (auto& val : nums) {
            if (cur_idx % 2 == 0) {
                cur_val = val;
                cur_idx++;
            } else {
                if (cur_val != val) {
                    cur_idx++;
                }
            }
        }
        if (cur_idx % 2 == 1) {
            cur_idx--;
        }
        return nums.size() - cur_idx;
    }
};


int main() {}
