/*
 * b.cpp
 *
 * Create Date : 2022-02-06 11:33:46
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long smallestNumber(long long num) {
        if (num == 0) {
            return 0;
        }
        std::vector<int> vals;
        bool is_minus = num < 0;
        num = std::abs(num);
        int zeros = 0;
        while (num > 0) {
            int res = num % 10;
            if (res == 0) {
                zeros++;
            } else {
                vals.emplace_back(res);
            }
            num /= 10;
        }

        if (is_minus) {
            std::sort(vals.begin(), vals.end(), std::greater<>());
        } else {
            std::sort(vals.begin(), vals.end());
        }

        long long ans = vals[0];
        if (!is_minus) {
            for (int i = 0; i < zeros; i++) {
                ans = ans * 10;
            }
        }
        for (int i = 1; i < vals.size(); i++) {
            ans = ans * 10 + vals[i];
        }
        if (is_minus) {
            for (int i = 0; i < zeros; i++) {
                ans = ans * 10;
            }
            ans *= -1;
        }
        return ans;
    }
};


int main() {}
