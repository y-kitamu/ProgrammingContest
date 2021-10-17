/*
 * a.cpp
 *
 * Create Date : 2021-10-17 11:29:05
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    bool areNumbersAscending(std::string s) {
        std::string cur = "";
        bool is_num = false;
        int min = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (is_num) {
                    int num = std::stoi(cur);
                    if (min >= num) {
                        return false;
                    }
                    min = num;
                    is_num = false;
                }
                cur = "";
            } else {
                cur += s[i];
                if (s[i] - '0' < 10) {
                    is_num = true;
                }
            }
        }
        if (is_num) {
            int num = std::stoi(cur);
            if (min >= num) {
                return false;
            }
        }
        return true;
    }
};


int main() {}
