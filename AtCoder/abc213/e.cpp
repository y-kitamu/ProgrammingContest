/*
 * e.cpp
 *
 * Create Date : 2021-08-08 21:35:16
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<char>> S(H, std::vector<char>(W));
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            std::cin >> S[y][x];
        }
    }
    auto T = S;

    std::deque<std::pair<int, int>> que;
    std::vector<std::vector<int>> score(H, std::vector<int>(W, 1e9));
    que.push_back(std::make_pair(0, 0));

    auto push = [&que, &T, &score, &W, &H](int x, int y, int cur) {
        if (x < 0 || x >= W || y < 0 || y >= H) {
            return;
        }
        if (T[y][x] == '#') {
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (y + dy < 0 || y + dy >= H || x + dx < 0 || x + dx >= W) {
                        continue;
                    }
                    if (cur + 1 < score[y + dy][x + dx]) {
                        que.push_back(std::make_pair((y + dy) * W + (x + dx), cur + 1));
                    }
                }
            }
        } else {
            if (cur < score[y][x]) {
                que.push_front(std::make_pair(y * W + x, cur));
            }
        }
    };

    while (!que.empty()) {
        auto front = que.front();
        auto y = front.first / W;
        auto x = front.first % W;
        // std::cout << x << " , " << y << ", " << front.second << std::endl;
        que.pop_front();
        if (score[y][x] <= front.second) {
            continue;
        }
        score[y][x] = front.second;
        push(x - 1, y, score[y][x]);
        push(x + 1, y, score[y][x]);
        push(x, y - 1, score[y][x]);
        push(x, y + 1, score[y][x]);
    }

    std::cout << score[H - 1][W - 1] << std::endl;
}
