/*
 * d.cpp
 *
 * Create Date : 2021-08-11 21:29:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    int cx, cy, dx, dy;
    std::cin >> cy >> cx >> dy >> dx;
    cx--, cy--;
    dx--, dy--;

    std::vector<std::vector<char>> grid(H, std::vector<char>(W));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> grid[y][x];
        }
    }

    std::vector<std::vector<int>> score(H, std::vector<int>(W, 1e9));
    std::deque<std::pair<int, int>> que;

    auto push = [&que, &score, &grid, &H, &W](int cx, int cy) {
        int cur = score[cy][cx];
        for (int dy = -2; dy <= 2; dy++) {
            for (int dx = -2; dx <= 2; dx++) {
                int x = cx + dx, y = cy + dy;
                if (x < 0 || x >= W || y < 0 || y >= H) {
                    continue;
                }
                if (grid[y][x] == '.') {
                    if (cur + 1 < score[y][x]) {
                        score[y][x] = cur + 1;
                        que.push_back(std::make_pair(x, y));
                    }
                }
            }
        }
        if (cx - 1 >= 0 && grid[cy][cx - 1] == '.' && cur < score[cy][cx - 1]) {
            score[cy][cx - 1] = cur;
            que.push_front(std::make_pair(cx - 1, cy));
        }
        if (cx + 1 < W && grid[cy][cx + 1] == '.' && cur < score[cy][cx + 1]) {
            score[cy][cx + 1] = cur;
            que.push_front(std::make_pair(cx + 1, cy));
        }
        if (cy - 1 >= 0 && grid[cy - 1][cx] == '.' && cur < score[cy - 1][cx]) {
            score[cy - 1][cx] = cur;
            que.push_front(std::make_pair(cx, cy - 1));
        }
        if (cy + 1 < H && grid[cy + 1][cx] == '.' && cur < score[cy + 1][cx]) {
            score[cy + 1][cx] = cur;
            que.push_front(std::make_pair(cx, cy + 1));
        }
    };


    score[cy][cx] = 0;
    push(cx, cy);

    while (!que.empty()) {
        auto front = que.front();
        que.pop_front();
        if (front.first == dx && front.second == dy) {
            break;
        }
        push(front.first, front.second);
    }
    if (score[dy][dx] == 1e9) {
        score[dy][dx] = -1;
    }
    std::cout << score[dy][dx] << std::endl;
}
