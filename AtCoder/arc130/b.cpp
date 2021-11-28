/*
 * b.cpp
 *
 * Create Date : 2021-11-28 21:04:50
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int H, W, C, Q;
    std::cin >> H >> W >> C >> Q;

    std::vector<int> t(Q), n(Q), c(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> t[i] >> n[i] >> c[i];
        c[i]--;
        n[i]--;
    }

    long long int rh = H;
    long long int rw = W;
    std::vector<long long int> ans(C, 0);
    std::set<int> hflag, wflag;

    for (int i = Q - 1; i >= 0; i--) {
        if (t[i] == 1) {
            if (hflag.find(n[i]) == hflag.end()) {
                ans[c[i]] += rw;
                hflag.insert(n[i]);
                rh--;
            }
        } else {
            if (wflag.find(n[i]) == wflag.end()) {
                ans[c[i]] += rh;
                wflag.insert(n[i]);
                rw--;
            }
        }
    }
    for (int i = 0; i < C; i++) {
        std::cout << ans[i];
        if (i < C - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
