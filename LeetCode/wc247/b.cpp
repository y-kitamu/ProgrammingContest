/*
 * b.cpp
 *
 * Create Date : 2021-06-27 11:32:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<std::vector<int>> rotateGrid(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int num_layer = std::min(m, n) / 2;
        std::vector<std::vector<int>> rotated(m, std::vector<int>(n));

        for (int i = 0; i < num_layer; i++) {
            int left = i, top = i;
            int right = n - i, bottom = m - i;
            int length = (right - left + bottom - top - 2) * 2;
            int offset = k % length;
            std::vector<int*> src(length), dst(length);

            for (int x = 0; x < right - left - 1; x++) {
                src[x] = &grid[top][left + x];
                dst[x] = &rotated[top][left + x];
                src[x + length / 2] = &grid[bottom - 1][right - x - 1];
                dst[x + length / 2] = &rotated[bottom - 1][right - x - 1];
            }

            for (int y = 0; y < bottom - top - 1; y++) {
                src[right - left - 1 + y] = &grid[top + y][right - 1];
                dst[right - left - 1 + y] = &rotated[top + y][right - 1];
                src[length - y - 1] = &grid[top + y + 1][left];
                dst[length - y - 1] = &rotated[top + y + 1][left];
            }

            for (int i = 0; i < length; i++) {
                // std::cout << *src[i] << " ";
                *dst[i] = *src[(i + offset) % length];
            }
            // std::cout << std::endl;
        }
        return rotated;
    }
};

int main() {}
