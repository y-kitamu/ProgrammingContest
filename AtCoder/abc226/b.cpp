/*
 * b.cpp
 *
 * Create Date : 2021-11-07 21:01:27
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::set<std::vector<int>> set;
    for (int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        std::vector<int> vec(L);
        for (int j = 0; j < L; j++) {
            std::cin >> vec[j];
        }
        set.insert(vec);
    }
    std::cout << set.size() << std::endl;
}
