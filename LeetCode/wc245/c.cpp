/*
 * c.cpp
 *
 * Create Date : 2021-06-13 11:54:08
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        bool fa = false, fb = false, fc = false;
        for (int i = 0; i < triplets.size(); i++) {
            auto t = triplets[i];
            if (t[0] == target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                fa = true;
            }
            if (t[0] <= target[0] && t[1] == target[1] && t[2] <= target[2]) {
                fb = true;
            }
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] == target[2]) {
                fc = true;
            }
        }
        return fa && fb && fc;
    }
};


int main() {}
