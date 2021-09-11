/*
 * d.cpp
 *
 * Create Date : 2021-09-11 21:40:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> xs(N), ys(N);
    std::set<int> set_x, set_y;
    for (int i = 0; i < N; i++) {
        std::cin >> xs[i] >> ys[i];
        set_x.insert(xs[i]);
        set_y.insert(ys[i]);
    }

    std::vector<std::vector<int>> map(set_y.size(), std::vector<int>(set_x.size()));
    for (int i = 0; i < N; i++) {
        auto nx = std::distance(set_x.begin(), set_x.find(xs[i]));
        xs[i] = nx;
        auto ny = std::distance(set_y.begin(), set_y.find(ys[i]));
        ys[i] = ny;
        map[ny][nx] = 1;
    }

    // for (int i = 0; i < map.size(); i++) {
    //     for (int j = 0; j < map[0].size(); j++) {
    //         std::cout << map[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        auto x1 = xs[i];
        auto y1 = ys[i];
        for (int j = i + 1; j < N; j++) {
            auto x2 = xs[j];
            auto y2 = ys[j];
            if (x1 == x2 || y1 == y2) {
                continue;
            }
            if (map[y2][x1] == 1 && map[y1][x2] == 1) {
                cnt++;
            }
        }
    }
    std::cout << cnt / 2 << std::endl;
}
