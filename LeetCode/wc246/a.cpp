/*
 * a.cpp
 *
 * Create Date : 2021-06-20 11:29:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::string largestOddNumber(std::string num) {
        std::string ans = "";
        int n = num.length();
        for (int i = 0; i < n; i++) {
            if ((num[n - i - 1] - '0') % 2 == 1) {
                ans = num.substr(0, n - i);
                break;
            }
        }
        return ans;
    }
};

int main() {}
