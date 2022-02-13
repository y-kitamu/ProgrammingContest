/*
 * b.cpp
 *
 * Create Date : 2022-02-13 11:32:10
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minimumOperations(std::vector<int>& nums) {
        std::map<int, int> c0, c1;
        c0[0] = 0;
        c1[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                c0[nums[i]]++;
            } else {
                c1[nums[i]]++;
            }
        }

        std::pair<int, int> p0 = *c0.begin();
        for (auto& p : c0) {
            if (p0.second < p.second) {
                p0 = p;
            }
        }
        std::pair<int, int> p1 = *c1.begin();
        for (auto& p : c1) {
            if (p1.second < p.second) {
                p1 = p;
            }
        }
        if (p1.first != p0.first) {
            return nums.size() - p0.second - p1.second;
        }
        std::pair<int, int> n0 = *c0.begin();
        for (auto& p : c0) {
            if (p0.first != p.first && n0.second < p.second) {
                n0 = p;
            }
        }
        std::pair<int, int> n1 = *c1.begin();
        for (auto& p : c1) {
            if (p1.first != p.first && n1.second < p.second) {
                n1 = p;
            }
        }
        int val0 = nums.size() - p0.second - n1.second;
        int val1 = nums.size() - n0.second - p1.second;
        return std::min(val0, val1);
    }
};


int main() {}
