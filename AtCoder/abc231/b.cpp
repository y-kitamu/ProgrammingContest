/*
 * b.cpp
 *
 * Create Date : 2021-12-11 21:01:55
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::map<std::string, int> map;
    for (int i = 0; i < N; i++) {
        std::string s;
        std::cin >> s;
        map[s]++;
    }

    std::string ans;
    int max = 0;
    for (auto& pair : map) {
        if (pair.second > max) {
            max = pair.second;
            ans = pair.first;
        }
    }

    std::cout << ans << std::endl;
}
