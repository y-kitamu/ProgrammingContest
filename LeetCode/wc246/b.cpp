/*
 * b.cpp
 *
 * Create Date : 2021-06-20 11:33:00
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int numberOfRounds(std::string startTime, std::string finishTime) {
        int sh = std::atoi(startTime.substr(0, 2).c_str());
        int sm = std::atoi(startTime.substr(3, 5).c_str());
        int fh = std::atoi(finishTime.substr(0, 2).c_str());
        int fm = std::atoi(finishTime.substr(3, 5).c_str());

        if (sh * 60 + sm > fh * 60 + fm) {
            fh += 24;
        }
        sm = (sm + 14) / 15;
        fm = fm / 15;

        return (fh * 4 + fm - (sh * 4 + sm));
    }
};

int main() {}
