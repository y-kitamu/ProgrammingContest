/*
 * c.cpp
 *
 * Create Date : 2021-08-22 11:40:46
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minimizeTheDifference(std::vector<std::vector<int>>& mat, int target) {
        std::vector<int> vals(801, 0), next(801);
        vals[0] = 1;

        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            next = std::vector<int>(801, 0);
            for (int j = 0; j < vals.size(); j++) {
                if (vals[j] == 1) {
                    for (int k = 0; k < n; k++) {
                        int idx = j + mat[i][k];
                        if (idx < 801) {
                            next[idx] = 1;
                        }
                    }
                }
            }
            for (int j = 0; j < 20; j++) {
                std::cout << next[j] << " ";
            }
            std::cout << std::endl;
            vals = next;
        }

        int ans = 1e9;
        for (int i = 0; i < vals.size(); i++) {
            if (vals[i] == 1) {
                ans = std::min(ans, std::abs(target - i));
            }
        }
        if (ans == int(1e9)) {
            ans = -target;
            for (int i = 0; i < m; i++) {
                int min = mat[i][0];
                for (int j = 1; j < n; j++) {
                    min = std::min(min, mat[i][j]);
                }
                ans += min;
            }
        }
        return ans;
    }
};


int main() {}
