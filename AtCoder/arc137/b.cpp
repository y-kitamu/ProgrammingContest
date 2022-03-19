/*
 * b.cpp
 *
 * Create Date : 2022-03-19 21:13:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    int sum = 0;
    int max = 0;
    int min = 0;
    int ans_max = 0;
    int ans_min = 0;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (a == 1) {
            sum++;
        } else {
            sum--;
        }
        max = std::max(max, sum);
        min = std::min(min, sum);
        ans_max = std::max(sum - min, ans_max);
        ans_min = std::max(max - sum, ans_min);
    }

    std::cout << ans_max + ans_min + 1 << std::endl;
}
