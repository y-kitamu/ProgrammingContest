/*
 * d.cpp
 *
 * Create Date : 2021-08-22 12:10:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> recoverArray(int n, std::vector<int>& sums) {
        std::sort(sums.begin(), sums.end());
        int tot = 0;
        for (auto& c : sums) {
            tot += c;
        }
        tot /= (1 << (n - 1));

        for (int i = 0; i < n; i++) {
        }
    }
};


int main() {}
