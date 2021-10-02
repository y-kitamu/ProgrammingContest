/*
 * a.cpp
 *
 * Create Date : 2021-10-02 20:54:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;
    int scale = 1;
    for (int i = 0; i < A - B; i++) {
        scale *= 32;
    }
    std::cout << scale << std::endl;
}
