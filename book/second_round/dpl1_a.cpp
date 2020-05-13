/*
 * dpl1_a.cpp
 *
 * Create Date : 2020-05-13 22:16:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

static constexpr int MAX = 100000000;

int search(int price, std::vector<int> &numbers, const std::vector<int>& coins) {
    if (price < 1) {
        return MAX;
    }
    if (numbers[price] != -1) {
        return numbers[price];
    }

    for (auto c : coins) {
        int val = search(price - c, numbers, coins);
        if (numbers[price] == -1 || val + 1 < numbers[price]) {
            numbers[price] = val + 1;
        }
    }
    return numbers[price];
}


int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> coins(m);
    std::vector<int> numbers(n + 1, -1);

    for (int i = 0; i < m; i++){
        std::cin >> coins[i];
        numbers[coins[i]] = 1;
    }

    int val = search(n, numbers, coins);
    std::cout << val <<std::endl;
}
