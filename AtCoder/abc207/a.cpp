/*
 * a.cpp
 *
 * Create Date : 2021-06-26 20:56:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::vector<int> v(3);
    std::cin >> v[0] >> v[1] >> v[2];

    std::sort(v.begin(), v.end());

    std::cout << v[1] + v[2] << std::endl;
}
