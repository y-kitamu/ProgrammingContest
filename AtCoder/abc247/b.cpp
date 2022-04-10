/*
 * b.cpp
 *
 * Create Date : 2022-04-10 21:02:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<std::string> s(N), t(N);
    for (int i = 0; i < N; i++) {
        std::cin >> s[i] >> t[i];
    }

    for (int i = 0; i < N; i++) {
        bool sflag = true, tflag = true;
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            if (s[i] == s[j] || s[i] == t[j]) {
                sflag = false;
            }
            if (t[i] == t[j] || t[i] == s[j]) {
                tflag = false;
            }
        }

        if (!sflag && !tflag) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
