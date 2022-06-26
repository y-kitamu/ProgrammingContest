/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-26 11:29:35
 */
#include <bits/stdc++.h>


class Solution {
  public:
    bool checkXMatrix(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (x == y || n - 1 - x == y || x == n - 1 - y) {
                    if (grid[x][y] == 0) {
                        return false;
                    }
                } else {
                    if (grid[x][y] != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
}
