/*
 * c.cpp
 *
 * Create Date : 2022-02-20 11:45:54
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string repeatLimitedString(std::string s, int repeatLimit) {
        std::vector<int> cnts(26, 0);
        for (auto& val : s) {
            cnts[val - 'a']++;
        }

        std::string ans;
        int prev = -1;
        bool flag = true;
        while (flag) {
            flag = false;
            bool maxi = true;
            for (int i = 25; i >= 0; i--) {
                if (cnts[i] > 0 && prev != i) {
                    int n;
                    if (maxi) {
                        n = std::min(cnts[i], repeatLimit);
                    } else {
                        n = 1;
                    }
                    cnts[i] -= n;
                    for (int j = 0; j < n; j++) {
                        ans += ('a' + i);
                    }
                    flag = true;
                    prev = i;
                    break;
                }
                if (cnts[i] > 0 && i == prev) {
                    maxi = false;
                }
            }
        }

        return ans;
    }
};


int main() {}
