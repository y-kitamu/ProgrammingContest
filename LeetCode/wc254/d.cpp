/*
 * d.cpp
 *
 * Create Date : 2021-08-15 12:11:43
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int latestDayToCross(int row, int col, std::vector<std::vector<int>>& cells) {
        for (auto& val : cells) {
            val[0]--, val[1]--;
        }
        int min = 0, max = cells.size();
        while (min != max) {
            int mid = (min + max + 1) / 2;
            if (judge(mid, row, col, cells)) {
                min = mid;
            } else {
                max = mid - 1;
            }
        }
        return min;
    }

    bool judge(int idx, int row, int col, std::vector<std::vector<int>>& cells) {
        std::vector<std::vector<int>> map(row, std::vector<int>(col, 0));
        for (int i = 0; i < idx; i++) {
            map[cells[i][0]][cells[i][1]] = 1;
        }

        std::queue<std::pair<int, int>> que;
        for (int i = 0; i < col; i++) {
            if (map[0][i] == 0) {
                que.push(std::make_pair(0, i));
                map[0][i] = 1;
            }
        }

        bool flag = false;
        while (!que.empty()) {
            auto front = que.front();
            auto cy = front.first, cx = front.second;
            std::cout << cy << " , " << cx << std::endl;
            if (cy == row - 1) {
                flag = true;
                break;
            }
            que.pop();

            if (cy < row - 1 && map[cy + 1][cx] == 0) {
                map[cy + 1][cx] = 1;
                que.push(std::make_pair(cy + 1, cx));
            }

            if (cx < col - 1 && map[cy][cx + 1] == 0) {
                map[cy][cx + 1] = 1;
                que.push(std::make_pair(cy, cx + 1));
            }

            if (cy > 0 && map[cy - 1][cx] == 0) {
                map[cy - 1][cx] = 1;
                que.push(std::make_pair(cy - 1, cx));
            }

            if (cx > 0 && map[cy][cx - 1] == 0) {
                map[cy][cx - 1] = 1;
                que.push(std::make_pair(cy, cx - 1));
            }
        }

        return flag;
    }
};

int main() {}
