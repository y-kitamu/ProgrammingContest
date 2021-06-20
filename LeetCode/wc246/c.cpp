/*
 * c.cpp
 *
 * Create Date : 2021-06-20 11:40:42
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();

        int idx = 1;
        std::vector<std::vector<int>> color(n, std::vector<int>(m, 0));
        std::vector<std::vector<int>> link;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 0) {
                    continue;
                }
                if (i > 0 && color[i - 1][j] > 0) {
                    color[i][j] = color[i - 1][j];
                }
                if (j > 0 && color[i][j - 1] > 0) {
                    if (color[i][j] > 0) {
                        link.push_back({color[i][j], color[i][j - 1]});
                    } else {
                        color[i][j] = color[i][j - 1];
                    }
                }
                if (color[i][j] == 0) {
                    color[i][j] = idx;
                    idx++;
                }
            }
        }

        std::vector<int> roots(idx);
        std::iota(roots.begin(), roots.end(), 0);
        auto find_root = [&roots](auto idx) {
            std::vector<int> updates;
            while (roots[idx] != idx) {
                updates.emplace_back(idx);
                idx = roots[idx];
            }
            for (auto& i : updates) {
                roots[i] = idx;
            }
            return idx;
        };

        for (auto& l : link) {
            auto lr = find_root(l[0]);
            auto rr = find_root(l[1]);
            roots[rr] = lr;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                color[i][j] = find_root(color[i][j]);
                std::cout << color[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << idx << std::endl;
        std::vector<int> sub(idx, 0);
        for (int i = 0; i < idx; i++) {
            if (find_root(i) == i) {
                sub[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto c = color[i][j];
                if (c > 0) {
                    sub[c] &= (grid1[i][j] == 1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += sub[i];
        }
        return ans;
    }
};

int main() {}
