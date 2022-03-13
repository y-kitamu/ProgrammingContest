/*
 * b.cpp
 *
 * Create Date : 2022-03-13 11:36:12
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int digArtifacts(int n, std::vector<std::vector<int>>& artifacts,
                     std::vector<std::vector<int>>& dig) {
        std::vector<std::vector<int>> map(n, std::vector<int>(n, 0));
        std::vector<std::vector<int>> sums(n + 1, std::vector<int>(n + 1, 0));

        for (auto& d : dig) {
            map[d[0]][d[1]] = 1;
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                sums[r + 1][c + 1] = sums[r][c + 1] + sums[r + 1][c] - sums[r][c] + map[r][c];
            }
        }

        int cnts = 0;
        for (auto& art : artifacts) {
            int t = art[0], l = art[1], b = art[2] + 1, r = art[3] + 1;
            int expect = (b - t) * (r - l);
            int val = sums[b][r] - sums[b][l] - sums[t][r] + sums[t][l];
            if (val == expect) {
                cnts++;
            }
        }
        return cnts;
    }
};


int main() {}
