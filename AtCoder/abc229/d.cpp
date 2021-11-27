/*
 * d.cpp
 *
 * Create Date : 2021-11-27 21:10:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    int K;
    std::cin >> S >> K;

    int left = 0, right = 0;
    int max = 0;
    while (left < S.length() && right < S.length()) {
        if (S[right] == 'X') {
            right++;
        } else if (K > 0) {
            K--;
            right++;
        } else {
            if (S[left] == '.') {
                K++;
            }
            left++;
        }
        max = std::max(right - left, max);
    }
    std::cout << max << std::endl;
}
