/*
 * b.cpp
 *
 * Create Date : 2022-03-26 21:02:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::set<int> A;

    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A.insert(a);
    }

    for (int i = 0; i <= 2001; i++) {
        if (A.find(i) == A.end()) {
            std::cout << i << std::endl;
            return 0;
        }
    }
}
