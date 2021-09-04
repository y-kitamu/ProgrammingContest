/*
 * d.cpp
 *
 * Create Date : 2021-09-04 21:08:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int L, Q;
    std::cin >> L >> Q;

    std::set<int> cuts;
    cuts.insert(0);
    cuts.insert(L);
    for (int i = 0; i < Q; i++) {
        int c, x;
        std::cin >> c >> x;
        if (c == 1) {
            cuts.insert(x);
        } else {
            auto itr = cuts.upper_bound(x);
            auto rhs = *itr--;
            auto lhs = *itr;
            std::cout << rhs - lhs << std::endl;
        }
    }
}
