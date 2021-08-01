/*
 * c.cpp
 *
 * Create Date : 2021-08-01 11:40:32
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long minimumPerimeter(long long neededApples) {
        long long int min = 1, max = 1e5;
        while (min != max) {
            long long int mid = (min + max) / 2;
            if (calc(mid, neededApples)) {
                max = mid;
            } else {
                min = mid + 1;
            }
        }
        return min * 8;
    }

    bool calc(long long int n, long long int target) { return 2 * n * (n + 1) * (2 * n + 1) >= target; }
};

int main() {}
