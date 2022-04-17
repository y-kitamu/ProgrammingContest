/*
 * c.cpp
 *
 * Create Date : 2022-04-17 11:40:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int maxTrailingZeros(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::vector<std::vector<int>> cnt2s(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> cnt5s(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> r2(rows + 1, std::vector<int>(cols + 1, 0));
        std::vector<std::vector<int>> r5(rows + 1, std::vector<int>(cols + 1, 0));
        std::vector<std::vector<int>> c2(rows + 1, std::vector<int>(cols + 1, 0));
        std::vector<std::vector<int>> c5(rows + 1, std::vector<int>(cols + 1, 0));

        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                int val = grid[y][x];
                int cnt2 = 0, cnt5 = 0;
                while (val % 2 == 0) {
                    val /= 2;
                    cnt2++;
                }
                while (val % 5 == 0) {
                    val /= 5;
                    cnt5++;
                }
                r2[y + 1][x + 1] = r2[y + 1][x] + cnt2;
                r5[y + 1][x + 1] = r5[y + 1][x] + cnt5;
                c2[y + 1][x + 1] = c2[y][x + 1] + cnt2;
                c5[y + 1][x + 1] = c5[y][x + 1] + cnt5;
                cnt2s[y][x] = cnt2;
                cnt5s[y][x] = cnt5;
            }
        }

        // auto print_mat = [](auto& mat) {
        //     for (auto& vec : mat) {
        //         for (auto& val : vec) {
        //             std::cout << val << " ";
        //         }
        //         std::cout << std::endl;
        //     }
        // };
        // std::cout << "r2" << std::endl;
        // print_mat(r2);
        // std::cout << "r5" << std::endl;
        // print_mat(r5);
        // std::cout << "c2" << std::endl;
        // print_mat(c2);
        // std::cout << "c5" << std::endl;
        // print_mat(c5);

        int ans = 0;
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                int tl2 = r2[y + 1][x + 1] - r2[y + 1][0] + c2[y + 1][x + 1] - c2[0][x + 1];
                int tl5 = r5[y + 1][x + 1] - r5[y + 1][0] + c5[y + 1][x + 1] - c5[0][x + 1];
                int tl = std::min(tl2 - cnt2s[y][x], tl5 - cnt5s[y][x]);
                //
                int tr2 = r2[y + 1][cols] - r2[y + 1][x] + c2[y + 1][x + 1] - c2[0][x + 1];
                int tr5 = r5[y + 1][cols] - r5[y + 1][x] + c5[y + 1][x + 1] - c5[0][x + 1];
                int tr = std::min(tr2 - cnt2s[y][x], tr5 - cnt5s[y][x]);
                //
                int bl2 = r2[y + 1][x + 1] - r2[y + 1][0] + c2[rows][x + 1] - c2[y][x + 1];
                int bl5 = r5[y + 1][x + 1] - r5[y + 1][0] + c5[rows][x + 1] - c5[y][x + 1];
                int bl = std::min(bl2 - cnt2s[y][x], bl5 - cnt5s[y][x]);
                //
                int br2 = r2[y + 1][cols] - r2[y + 1][x] + c2[rows][x + 1] - c2[y][x + 1];
                int br5 = r5[y + 1][cols] - r5[y + 1][x] + c5[rows][x + 1] - c5[y][x + 1];
                int br = std::min(br2 - cnt2s[y][x], br5 - cnt5s[y][x]);

                int val = std::max(std::max(tl, tr), std::max(br, bl));
                ans = std::max(val, ans);
                // std::cout << "(" << tl5 << ", " << tr5 << ", " << bl5 << ", " << br5 << ") ";
                // std::cout << val << " ";
            }
            // std::cout << std::endl;
        }
        return ans;
    }
};

int main() {}
