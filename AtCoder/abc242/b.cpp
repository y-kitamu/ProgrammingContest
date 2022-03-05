/*
 * b.cpp
 *
 * Create Date : 2022-03-05 21:03:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    std::vector<int> vec(S.length());

    for (int i = 0; i < S.length(); i++) {
        vec[i] = (int)(S[i] - 'a');
    }

    std::sort(vec.begin(), vec.end());
    std::string ans = "";
    for (auto& v : vec) {
        ans += (char)('a' + v);
    }
    std::cout << ans << std::endl;
}
