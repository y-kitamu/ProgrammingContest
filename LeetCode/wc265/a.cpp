/*
 * a.cpp
 *
 * Create Date : 2021-10-31 11:29:07
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int smallestEqual(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i % 10 == nums[i]) {
                return i;
            }
        }
        return -1;
    }
};


int main() {}
