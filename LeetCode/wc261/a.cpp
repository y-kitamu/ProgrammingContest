/*
 * a.cpp
 *
 * Create Date : 2021-10-03 11:27:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minimumMoves(std::string s) {
        int n = 0;
        int cnt = 0;
        while (n < s.length()) {
            if (s[n] == 'O') {
                n++;
            } else {
                cnt++;
                n += 3;
            }
        }
        return cnt;
    }
};

int main() {}
