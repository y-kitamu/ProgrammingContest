/*
 * c.cpp
 *
 * Create Date : 2021-07-18 11:42:51
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long maxPoints(std::vector<std::vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        std::vector<long long int> scores(n);
        std::vector<long long int> sum(n, 0);
        for (int x = 0; x < n; x++) {
            sum[x] = points[0][x];
        }
        for (int y = 1; y < m; y++) {
            scores = sum;
            for (int x = 1; x < n; x++) {
                scores[x] = std::max(scores[x - 1] - 1, scores[x]);
            }
            for (int x = n - 2; x >= 0; x--) {
                scores[x] = std::max(scores[x + 1] - 1, scores[x]);
            }
            for (int x = 0; x < n; x++) {
                sum[x] = (long long int)scores[x] + points[y][x];
            }
        }
        long long int max = 0;
        for (auto& val : sum) {
            max = std::max(val, max);
        }
        return max;
    }
};

int main() {}
