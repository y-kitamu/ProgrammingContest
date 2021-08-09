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
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            std::cin >> S[h][w];
        }
    }

    std::vector<int> roots(H * W);
    std::iota(roots.begin(), roots.end(), 0);
    auto find_root = [&roots](int idx) {
        std::vector<int> update;
        while (roots[idx] != idx) {
            update.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& i : update) {
            roots[i] = idx;
        }
        return idx;
    };

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (S[h][w] == '#') {
                continue;
            }
            int idx = h * W + w;
            auto root = find_root(idx);
            if (h > 0 && S[h - 1][w] == '.') {
                auto prev = find_root(idx - W);
                roots[std::max(prev, root)] = std::min(prev, root);
                root = find_root(idx);
            }
            if (w > 0 && S[h][w - 1] == '.') {
                auto prev = find_root(idx - 1);
                roots[std::max(root, prev)] = std::min(prev, root);
                root = find_root(idx);
            }
        }
    }

    std::vector<int> counts(H * W, -1);
    counts[0] = 0;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int idx = h * W + w;
            auto cnt = counts[find_root(idx)];
            // std::cout << find_root(idx) << " ";
            for (int dy = std::max(h - 2, 0); dy <= std::min(H - 1, h + 2); dy++) {
                for (int dx = std::max(w - 2, 0); dx <= std::min(W - 1, w + 2); dx++) {
                    if (std::abs(w - dx) + std::abs(h - dy) == 4) {
                        continue;
                    }
                    int root = find_root(dy * W + dx);
                    if (S[h][w] == '#') {
                        if (counts[root] == -1 || cnt + 1 < counts[root]) {
                            counts[root] = cnt + 1;
                        }
                    } else {
                        if (dy > 0) {
                            int c = counts[find_root((dy - 1) * W + dx)];
                            counts[root] = std::min(c, counts[root]);
                        }
                        if (dx > 0) {
                            int c = counts[find_root(dy * W + dx - 1)];
                            counts[root] = std::min(c, counts[root]);
                        }
                    }
                }
            }
            // std::cout << counts[find_root(idx)] << " ";
        }
        // std::cout << std::endl;
    }

    std::cout << counts[find_root(H * W - 1)] << std::endl;
}
