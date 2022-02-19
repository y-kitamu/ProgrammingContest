/*
 * a.cpp
 *
 * Create Date : 2022-02-19 20:59:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int H;
    std::cin >> H;
    std::cout << std::fixed << std::setprecision(10) << std::sqrt(H * (12800000 + H)) << std::endl;
}
