/*
 * d.cpp
 *
 * Create Date : 2022-03-20 21:10:22
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::vector<char> S(3), T(3);
    std::cin >> S[0] >> S[1] >> S[2];
    std::cin >> T[0] >> T[1] >> T[2];
    std::vector<int> val(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (T[i] == S[j]) {
                val[i] = j;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (val[i] > val[j]) {
                cnt++;
            }
        }
    }
    if (cnt % 2 == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
