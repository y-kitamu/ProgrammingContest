/*
 * a.cpp
 *
 * Create Date : 2021-11-21 11:28:28
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maxDistance(std::vector<int>& colors) {
        int max = 0;
        for (int i = 0; i < colors.size(); i++) {
            for (int j = i + 1; j < colors.size(); j++) {
                if (colors[i] != colors[j]) {
                    max = std::max(j - i, max);
                }
            }
        }
        return max;
    }
};


int main() {}
