/*
 * a.cpp
 *
 * Create Date : 2021-12-19 11:28:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::string firstPalindrome(std::vector<std::string>& words) {
        for (auto& w : words) {
            int len = w.length();
            bool flag = true;
            for (int i = 0; i < len / 2; i++) {
                flag &= w[i] == w[len - i - 1];
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                return w;
            }
        }
        return "";
    }
};

int main() {}
