/*
 * c.cpp
 *
 * Create Date : 2021-08-10 20:05:27
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;
    std::vector<std::vector<char>> grid(H, std::vector<char>(W));

    int sx, sy, gx, gy;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> grid[y][x];
            if (grid[y][x] == 's') {
                sx = x;
                sy = y;
            }
            if (grid[y][x] == 'g') {
                gx = x;
                gy = y;
            }
        }
    }

    std::vector<std::vector<int>> cost(H, std::vector<int>(W, 1e9));
    std::deque<std::pair<int, int>> que;
    que.push_back(std::make_pair(sy * W + sx, 0));

    auto push = [&que, &grid, &cost, &W, &H](int x, int y, int cur) {
        if (x < 0 || x >= W || y < 0 || y >= H) {
            return;
        }

        if (grid[y][x] == '#') {
            if (cur + 1 < cost[y][x]) {
                que.push_back(std::make_pair(y * W + x, cur + 1));
            }
        } else {
            if (cur < cost[y][x]) {
                que.push_front(std::make_pair(y * W + x, cur));
            }
        }
    };

    while (!que.empty()) {
        auto front = que.front();
        que.pop_front();
        auto x = front.first % W;
        auto y = front.first / W;

        if (front.second < cost[y][x]) {
            cost[y][x] = front.second;
            push(x - 1, y, front.second);
            push(x + 1, y, front.second);
            push(x, y - 1, front.second);
            push(x, y + 1, front.second);
        }
    }

    if (cost[gy][gx] <= 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
