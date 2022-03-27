/*
 * a.cpp
 *
 * Create Date : 2022-03-27 11:29:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
public:
    std::vector<std::vector<int>> findDifference(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::set<int> n1, n2;
        for (auto& val : nums1) {
            n1.insert(val);
        }
        for (auto& val : nums2) {
            n2.insert(val);
        }
        std::vector<std::vector<int>> ans(2);
        for (auto itr = n1.begin(); itr != n1.end(); itr++) {
            if (n2.find(*itr) == n2.end()) {
                ans[0].emplace_back(*itr);
            }
        }
        for (auto itr = n2.begin(); itr != n2.end(); itr++) {
            if (n1.find(*itr) == n1.end()) {
                ans[1].emplace_back(*itr);
            }
        }
        return ans;
    }
};


int main() {}
