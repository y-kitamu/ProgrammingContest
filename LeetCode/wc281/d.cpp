/*
 * d.cpp
 *
 * Create Date : 2022-02-20 12:46:45
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long coutPairs(std::vector<int>& nums, int k) {
        std::map<int, long long> lcds;
        std::set<long long> vals;
        for (int i = 0; i < nums.size(); i++) {
            auto val = lcd(nums[i], k);
            lcds[val]++;
            vals.insert(val);
        }

        long long ans = 0;
        for (auto itr = vals.begin(); itr != vals.end(); itr++) {
            for (auto inner = itr; inner != vals.end(); inner++) {
                auto v1 = *itr;
                auto v2 = *inner;
                if (v1 * v2 % k == 0) {
                    if (v1 == v2) {
                        ans += lcds[v1] * (lcds[v1] - 1) / 2;
                    } else {
                        ans += lcds[v1] * lcds[v2];
                    }
                }
            }
        }
        return ans;
    }

    int lcd(int a, int b) {
        while (a % b > 0) {
            auto tmp = b;
            b = a % b;
            a = tmp;
        }
        return b;
    }
};

int main() {}
