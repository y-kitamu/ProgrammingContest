/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-04-24 11:37:43
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> countRectangles(std::vector<std::vector<int>>& rectangles,
                                     std::vector<std::vector<int>>& points) {
        auto sort_idx = [](auto& rects) {
            std::vector<int> indices(rects.size());
            std::iota(indices.begin(), indices.end(), 0);
            std::sort(indices.begin(), indices.end(),
                      [&rects](auto& lhs, auto& rhs) { return rects[lhs][0] < rects[rhs][0]; });
            return indices;
        };
        int max_y = 0;
        std::vector<int> sidx = sort_idx(rectangles);
        std::vector<int> rects(sidx.size());
        for (int i = 0; i < sidx.size(); i++) {
            rects[i] = rectangles[sidx[i]][0];
            max_y = std::max(max_y, rectangles[sidx[i]][1]);
        }
        for (auto& pt : points) {
            max_y = std::max(pt[1], max_y);
        }
        max_y++;

        std::vector<std::vector<int>> map(102, std::vector<int>(rectangles.size() + 1, 0));
        for (int i = 0; i < sidx.size(); i++) {
            auto& rect = rectangles[sidx[i]];
            map[rect[1] + 1][i + 1]++;
            map[rect[1] + 1][0]--;
            map[0][i + 1]--;
        }
        for (int y = 1; y <= max_y; y++) {
            for (int x = 1; x < map[0].size(); x++) {
                map[y][x] += map[y - 1][x] + map[y][0];
            }
        }

        std::vector<int> ans(points.size());
        for (int i = 0; i < points.size(); i++) {
            auto& pt = points[i];
            auto idx = std::distance(rects.begin(), std::lower_bound(rects.begin(), rects.end(), pt[0]));
            std::cout << idx << " , " << pt[1] << ", " << map[pt[1]][idx] << std::endl;

            ans[i] = rectangles.size() + map[pt[1]][idx];
        }

        return ans;
    }
};


int main() {}
