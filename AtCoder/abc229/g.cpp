/*
 * g.cpp
 *
 * Create Date : 2021-11-27 22:09:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    long long int K;
    std::cin >> S >> K;

    int didx = 0, yidx = 0;
    std::vector<long long int> ldcnt(1, 0), lycnt(1, 0);
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '.') {
            ldcnt[didx]++;
            if (lycnt[yidx] > 0) {
                yidx++;
                lycnt.emplace_back(0);
            }
        } else {
            lycnt[yidx]++;
            if (ldcnt[didx] > 0) {
                ldcnt.emplace_back(ldcnt[didx++]);
            }
        }
    }

    didx = 0, yidx = 0;
    std::vector<long long int> rdcnt(1, 0), rycnt(1, 0);
    for (int i = S.length() - 1; i >= 0; i--) {
        if (S[i] == '.') {
            rdcnt[didx]++;
            if (rycnt[yidx] > 0) {
                yidx++;
                lycnt.emplace_back(0);
            }
        } else {
            rycnt[yidx]++;
            if (rdcnt[didx] > 0) {
                rdcnt.emplace_back(rdcnt[didx++]);
            }
        }
    }
}
