/*
 * b.cpp
 *
 * Create Date : 2021-06-13 21:01:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> cnt(N, 0);
    bool flag = true;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        val--;
        cnt[val]++;
        if (cnt[val] > 1) {
            flag = false;
        }
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
