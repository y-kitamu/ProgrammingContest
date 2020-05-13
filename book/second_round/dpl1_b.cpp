/*
 * dpl1_b.cpp
 *
 * Create Date : 2020-05-13 22:35:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

struct Item {
    int value, weight;
};


int main() {
    int N, W;
    std::cin >> N >> W;

    std::vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        std::cin >> items[i].value >> items[i].weight;
    }

    std::vector<int> max_value(W + 1, 0);

    for (auto&& item : items) {
        for (int j = W; j >= item.weight; j--) {
            max_value[j] = std::max(max_value[j], max_value[j - item.weight] + item.value);
        }
    }

    std::cout << max_value[W] << std::endl;
}
