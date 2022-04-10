/*
 * a.cpp
 *
 * Create Date : 2022-04-10 20:59:21
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int S;
    std::cin >> S;
    S /= 10;

    std::string ans = "";
    for (int i = 0; i < 4; i++) {
        ans = (char)('0' + S % 10) + ans;
        S /= 10;
    }

    std::cout << ans << std::endl;
}
