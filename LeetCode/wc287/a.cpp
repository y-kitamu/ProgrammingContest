/*
 * a.cpp
 *
 * Create Date : 2022-04-03 11:27:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int convertTime(std::string current, std::string correct) {
        int cur_h = int(current[0] - '0') * 10 + int(current[1] - '0');
        int cur_m = int(current[3] - '0') * 10 + int(current[4] - '0');
        int cor_h = int(correct[0] - '0') * 10 + int(correct[1] - '0');
        int cor_m = int(correct[3] - '0') * 10 + int(correct[4] - '0');

        if (cor_m < cur_m) {
            cor_m += 60;
            cor_h--;
        }
        int dh = cor_h - cur_h;
        int dm = cor_m - cur_m;

        return dh + dm / 15 + (dm % 15) / 5 + dm % 5;
    }
};


int main() {}
