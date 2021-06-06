/*
 * a.cpp
 *
 * Create Date : 2021-06-06 11:26:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    bool findRotation(std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& target) {
        int n = mat.size();

        bool res = false;
        std::vector<std::vector<int>> next(n, std::vector<int>(n));
        for (int k = 0; k < 4; k++) {
            bool flag = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    flag &= target[i][j] == mat[n - j - 1][i];
                    next[i][j] = mat[n - j - 1][i];
                }
            }
            res |= flag;
            mat = next;
        }
        return res;
    }
};

int main() {}
