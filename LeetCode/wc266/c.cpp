/*
 * c.cpp
 *
 * Create Date : 2021-11-07 11:49:54
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minimizedMaximum(int n, std::vector<int>& quantities) {
        int min = 1;
        int max = quantities[0];
        for (auto& val : quantities) {
            max = std::max(max, val);
        }
        while (min != max) {
            int mid = (min + max) / 2;
            int cnt = 0;
            for (auto& val : quantities) {
                cnt += (val + mid - 1) / mid;
            }
            if (cnt <= n) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min;
    }
};

int main() {}
