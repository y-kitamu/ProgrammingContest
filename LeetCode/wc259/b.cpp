/*
 * b.cpp
 *
 * Create Date : 2021-09-19 11:32:21
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int sumOfBeauties(std::vector<int>& nums) {
        std::multiset<int> lhs, rhs;
        lhs.insert(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            rhs.insert(nums[i]);
        }
        int cnt = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            auto itr = rhs.find(nums[i]);
            int val = *itr;
            rhs.erase(itr);
            if (*lhs.rbegin() < val && val < *rhs.begin()) {
                cnt += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                cnt++;
            }
            lhs.insert(val);
        }
        return cnt;
    }
};

int main() {}
