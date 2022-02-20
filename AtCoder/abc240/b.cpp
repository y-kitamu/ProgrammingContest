/*
 * b.cpp
 *
 * Create Date : 2022-02-20 21:02:15
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::set<int> set;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        set.insert(a);
    }
    std::cout << set.size() << std::endl;
}
