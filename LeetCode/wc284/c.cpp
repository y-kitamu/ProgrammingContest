/*
 * c.cpp
 *
 * Create Date : 2022-03-13 11:48:13
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumTop(std::vector<int>& nums, int k) {
        if (nums.size() == 1) {
            if (k % 2 == 0) {
                return nums[0];
            } else {
                return -1;
            }
        }
        if (k == 1) {
            return nums[1];
        }

        int max = nums[0];
        for (int i = 1; i < std::min(k - 1, int(nums.size())); i++) {
            max = std::max(nums[i], max);
        }
        if (k < nums.size()) {
            max = std::max(nums[k], max);
        }
        return max;
    }
};

int main() {}
