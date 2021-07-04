/*
 * b.cpp
 *
 * Create Date : 2021-07-04 11:32:39
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int eliminateMaximum(std::vector<int>& dist, std::vector<int>& speed) {
        std::vector<int> cnts(dist.size());

        for (int i = 0; i < dist.size(); i++) {
            cnts[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        std::sort(cnts.begin(), cnts.end());

        for (int i = 0; i < cnts.size(); i++) {
            if (i >= cnts[i]) {
                return i;
            }
        }
        return cnts.size();
    }
};

int main() {}
