/*
 * b.cpp
 *
 * Create Date : 2021-11-13 21:05:45
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::set<int> set;
    for (int a = 1; a < 335; a++) {
        for (int b = 1; b < 335; b++) {
            auto val = 4 * a * b + 3 * a + 3 * b;
            set.insert(val);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int s;
        std::cin >> s;
        if (set.find(s) == set.end()) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}
