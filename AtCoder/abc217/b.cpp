/*
 * b.cpp
 *
 * Create Date : 2021-09-04 21:01:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string s1, s2, s3;
    std::map<std::string, int> m;
    m["ABC"] = 0;
    m["ARC"] = 0;
    m["AGC"] = 0;
    m["AHC"] = 0;
    std::cin >> s1 >> s2 >> s3;

    m[s1] = 1;
    m[s2] = 1;
    m[s3] = 1;
    for (auto& pair : m) {
        if (pair.second == 0) {
            std::cout << pair.first << std::endl;
        }
    }
}
