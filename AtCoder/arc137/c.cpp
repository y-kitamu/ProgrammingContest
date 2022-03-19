/*
 * c.cpp
 *
 * Create Date : 2022-03-19 21:27:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (a - N - 1 < 0) {
            continue;
        }
        a -= -N - 1;
        if (a == 0) {
            ans++;
        } else {
            ans += 2;
        }
    }

    if (ans % 2 == 0) {
        std::cout << "Bob" << std::endl;
    } else {
        std::cout << "Alice" << std::endl;
    }
}
