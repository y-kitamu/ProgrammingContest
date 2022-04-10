/*
 * c.cpp
 *
 * Create Date : 2022-04-10 21:06:47
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


void solve(int n) {
    if (n == 1) {
        std::cout << 1;
        return;
    }
    solve(n - 1);
    std::cout << " " << n << " ";
    solve(n - 1);
}


int main() {
    int N;
    std::cin >> N;
    solve(N);
    std::cout << std::endl;
}
