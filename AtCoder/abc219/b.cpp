/*
 * b.cpp
 *
 * Create Date : 2021-09-18 21:02:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string s1, s2, s3, t;
    std::cin >> s1 >> s2 >> s3 >> t;

    for (int i = 0; i < t.length(); i++) {
        if (t[i] == '1') {
            std::cout << s1;
        } else if (t[i] == '2') {
            std::cout << s2;
        } else {
            std::cout << s3;
        }
    }
    std::cout << std::endl;
}
