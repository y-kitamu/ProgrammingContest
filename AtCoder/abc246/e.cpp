/*
 * e.cpp
 *
 * Create Date : 2022-04-02 21:21:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    int ax, ay, bx, by;
    std::cin >> ax >> ay >> bx >> by;
    ax--, ay--, bx--, by--;

    std::vector<std::string> S(N);
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    // if (std::abs(ax - bx + ay - by) % 2 != 0) {
    //     std::cout << -1 << std::endl;
    //     return 0;
    // }

    int MAX = 1e7;
    std::vector<std::vector<int>> flag(N, std::vector<int>(N, MAX));
    std::queue<std::vector<int>> que;
    flag[ay][ax] = 0;
    que.push({ax, ay});

    while (!que.empty()) {
        auto top = que.front();
        que.pop();
        auto x = top[0], y = top[1];
        for (int d = 1; d < std::min(N - x, N - y); d++) {
            if (flag[y + d][x + d] <= flag[y][x] || S[y + d][x + d] == '#') {
                break;
            }
            if (flag[y][x] + 1 < flag[y + d][x + d]) {
                flag[y + d][x + d] = flag[y][x] + 1;
                que.push({x + d, y + d});
            }
        }
        for (int d = 1; d < std::min(N - x, y + 1); d++) {
            if (flag[y - d][x + d] <= flag[y][x] || S[y - d][x + d] == '#') {
                break;
            }
            if (flag[y][x] + 1 < flag[y - d][x + d]) {
                flag[y - d][x + d] = flag[y][x] + 1;
                que.push({x + d, y - d});
            }
        }
        for (int d = 1; d < std::min(x + 1, N - y); d++) {
            if (flag[y + d][x - d] <= flag[y][x] || S[y + d][x - d] == '#') {
                break;
            }
            if (flag[y][x] + 1 < flag[y + d][x - d]) {
                flag[y + d][x - d] = flag[y][x] + 1;
                que.push({x - d, y + d});
            }
        }
        for (int d = 1; d < std::min(x + 1, y + 1); d++) {
            if (flag[y - d][x - d] <= flag[y][x] || S[y - d][x - d] == '#') {
                break;
            }
            if (flag[y][x] + 1 < flag[y - d][x - d]) {
                flag[y - d][x - d] = flag[y][x] + 1;
                que.push({x - d, y - d});
            }
        }
    }

    // for (auto& vec : flag) {
    //     for (auto& val : vec) {
    //         if (val == MAX) {
    //             std::cout << -1 << " ";
    //         } else {
    //             std::cout << val << " ";
    //         }
    //     }
    //     std::cout << std::endl;
    // }

    if (flag[by][bx] == MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << flag[by][bx] << std::endl;
    }
}
