/*
 * b.cpp
 *
 * Create Date : 2021-09-26 11:35:12
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long gridGame(std::vector<std::vector<int>>& grid) {
        int n = grid[0].size();
        std::vector<long long int> sum0(n + 1, 0), sum1(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum0[i + 1] = sum0[i] + grid[0][i];
            sum1[i + 1] = sum1[i] + grid[1][i];
        }
        long long int max = 1e18;

        for (int i = 0; i < n; i++) {
            auto top = sum0[n] - sum0[i + 1];
            auto bot = sum1[i] - sum1[0];
            auto val = std::max(top, bot);
            max = std::min(val, max);
        }
        return max;
    }
};

int main() {}
