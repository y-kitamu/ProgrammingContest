/*
 * b.cpp
 *
 * Create Date : 2021-10-03 11:33:37
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) {
        auto sum = (long long)mean * (long long)(n + rolls.size());
        for (auto& val : rolls) {
            sum -= val;
        }
        long long int a = sum / n;
        if (a < 1 || a > 6) {
            return std::vector<int>();
        }
        long long int x = n * (a + 1) - sum;
        std::vector<int> ans(n, a);
        for (int i = x; i < n; i++) {
            ans[i] = a + 1;
            if (a + 1 > 6) {
                return std::vector<int>();
            }
        }
        return ans;
    }
};

int main() {}
