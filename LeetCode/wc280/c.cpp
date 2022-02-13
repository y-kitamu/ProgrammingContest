/*
 * c.cpp
 *
 * Create Date : 2022-02-13 11:57:28
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long minimumRemoval(std::vector<int>& beans) {
        std::sort(beans.begin(), beans.end());
        long long int sum0 = 0, sum1 = 0;
        for (auto& val : beans) {
            sum1 += val - beans[0];
        }

        std::cout << sum0 << " , " << sum1 << std::endl;
        long long int ans = sum1;
        for (int i = 0; i < beans.size() - 1; i++) {
            long long int diff = beans[i + 1] - beans[i];
            sum0 += beans[i];
            sum1 -= diff * (beans.size() - i - 1);
            std::cout << sum0 << " , " << sum1 << std::endl;
            ans = std::min(sum0 + sum1, ans);
        }
        return ans;
    }
};

int main() {}
