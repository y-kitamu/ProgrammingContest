/*
 * c.cpp
 *
 * Create Date : 2021-12-19 11:36:32
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long getDescentPeriods(std::vector<int>& prices) {
        std::map<long long, long long> cnts;
        long long cnt = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i - 1] - prices[i] == 1) {
                cnt++;
            } else {
                if (cnt > 0) {
                    cnts[cnt]++;
                }
                cnt = 0;
            }
            // std::cout << " i = " << i << ", cnt = " << cnt << std::endl;
        }
        if (cnt > 0) {
            cnts[cnt]++;
        }

        long long ans = prices.size();
        for (auto& pair : cnts) {
            // std::cout << pair.first << ", " << pair.second << std::endl;
            ans += pair.first * (pair.first + 1) / 2 * pair.second;
        }
        return ans;
    }
};


int main() {}
