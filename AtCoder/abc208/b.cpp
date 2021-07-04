/*
 * b.cpp
 *
 * Create Date : 2021-07-04 21:01:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int p;
    std::cin >> p;
    int val = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;

    int cnt = 0;
    for (int i = 10; i >= 1; i--) {
        cnt += p / val;
        p -= p / val * val;
        val /= i;
    }
    std::cout << cnt << std::endl;
}
