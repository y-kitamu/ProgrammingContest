/*
 * a.cpp
 *
 * Create Date : 2022-03-06 11:29:23
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<std::string> cellsInRange(std::string s) {
        int cols = (int)(s[3] - s[0]) + 1;
        int rows = (int)(s[4] - s[1]) + 1;

        std::vector<std::string> ans(cols * rows);
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                ans[c * rows + r] = (char)(s[0] + c);
                ans[c * rows + r] += (char)(s[1] + r);
            }
        }
        return ans;
    }
};


int main() {}
