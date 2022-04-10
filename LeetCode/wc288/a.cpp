/*
 * a.cpp
 *
 * Create Date : 2022-04-10 11:28:28
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int largestInteger(int num) {
        std::vector<int> odds, evens;
        std::vector<int> flag;
        while (num > 0) {
            int val = num % 10;
            if (val % 2 == 0) {
                evens.emplace_back(val);
                flag.emplace_back(0);
            } else {
                odds.emplace_back(val);
                flag.emplace_back(1);
            }
            num /= 10;
        }

        int ans = 0;
        std::sort(odds.begin(), odds.end(), std::greater<>());
        std::sort(evens.begin(), evens.end(), std::greater<>());
        int oidx = 0, eidx = 0;
        for (int i = flag.size() - 1; i >= 0; i--) {
            ans *= 10;
            if (flag[i] == 0) {
                ans += evens[eidx++];
            } else {
                ans += odds[oidx++];
            }
        }
        return ans;
    }
};

int main() {}
