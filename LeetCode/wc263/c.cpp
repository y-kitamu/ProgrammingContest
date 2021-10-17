/*
 * c.cpp
 *
 * Create Date : 2021-10-17 11:49:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int countMaxOrSubsets(std::vector<int>& nums) {
        int max = 0;
        std::map<int, int> cnts;
        for (int i = 0; i < (1 << nums.size()); i++) {
            int num = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((i >> j) & 1) {
                    num = num | nums[j];
                }
            }
            if (num >= max) {
                if (cnts.find(num) == cnts.end()) {
                    cnts[num] = 0;
                }
                cnts[num]++;
                max = num;
            }
        }
        return cnts[max];
    }
};

int main() {}
