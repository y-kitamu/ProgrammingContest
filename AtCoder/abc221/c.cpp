/*
 * c.cpp
 *
 * Create Date : 2021-10-02 21:05:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    std::vector<int> N(S.length());
    for (int i = 0; i < S.length(); i++) {
        N[i] = (int)(S[i] - '0');
    }
    std::sort(N.begin(), N.end(), std::greater<>());

    int cnt = N.size() / 2 + N.size() % 2;

    long long int max = 0;
    for (int i = 0; i < (1 << cnt); i++) {
        long long int a = 0, b = 0;
        for (int j = 0; j < cnt; j++) {
            if (1 << j & i) {
                a = a * 10 + N[j * 2];
                if (j * 2 + 1 < N.size()) {
                    b = b * 10 + N[j * 2 + 1];
                }
            } else {
                b = b * 10 + N[j * 2];
                if (j * 2 + 1 < N.size()) {
                    a = a * 10 + N[j * 2 + 1];
                }
            }
        }
        max = std::max(a * b, max);
    }
    std::cout << max << std::endl;
}
