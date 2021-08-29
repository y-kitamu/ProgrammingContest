/*
 * b.cpp
 *
 * Create Date : 2021-08-29 11:34:01
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
        int max_len = nums[0].length();
        for (auto& str : nums) {
            max_len = std::max(max_len, (int)str.length());
        }
        for (int i = 0; i < nums.size(); i++) {
            std::string padded = "";
            for (int j = 0; j < max_len - nums[i].size(); j++) {
                padded += "0";
            }
            nums[i] = padded + nums[i];
        }
        std::sort(nums.begin(), nums.end());
        auto padded = nums[nums.size() - k];
        int idx = 0;
        while (idx < padded.length() && padded[idx] == '0') {
            idx++;
        }
        if (idx == padded.length()) {
            return "0";
        }
        return padded.substr(idx);
    }
};

int main() {}
