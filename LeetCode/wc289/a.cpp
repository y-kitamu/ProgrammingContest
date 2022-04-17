/*
 * a.cpp
 *
 * Create Date : 2022-04-17 11:29:37
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::string digitSum(std::string s, int k) {
        while (s.length() > k) {
            std::string next = "";
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                for (int j = i; j < std::min((int)s.length(), i + k); j++) {
                    sum += s[j] - '0';
                }
                next += std::to_string(sum);
            }
            s = next;
        }
        return s;
    }
};

int main() {}
