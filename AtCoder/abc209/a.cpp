/*
 * a.cpp
 *
 * Create Date : 2021-07-10 20:56:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;
    std::cout << std::max(B - A + 1, 0) << std::endl;
}
