/*
 * b.cpp
 *
 * Create Date : 2021-08-22 11:34:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {
        std::sort(nums.begin(), nums.end());
        std::string zeros = "";
        for (int i = 0; i < nums.size(); i++) {
            zeros += "0";
        }
        for (int i = 0; i < (1 << nums.size()); i++) {
            auto val = zeros;
            for (int j = 0; j < nums.size(); j++) {
                if (i & (1 << j)) {
                    val[j] = '1';
                }
            }
            if (std::find(nums.begin(), nums.end(), val) == nums.end()) {
                return val;
            }
        }
        return "";
    }
};


int main() {}
