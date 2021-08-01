/*
 * a.cpp
 *
 * Create Date : 2021-08-01 11:28:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    bool isThree(int n) {
        int max = std::sqrt(n) + 1;

        std::vector<int> vals;
        for (int i = 2; i <= std::min(max, n); i++) {
            while (n % i == 0) {
                n /= i;
                vals.emplace_back(i);
            }
        }
        if (n > 1) {
            vals.emplace_back(n);
        }

        return (vals.size() == 2) && (vals[0] == vals[1]);
    }
};

int main() {}
