/*
 * d.cpp
 *
 * Create Date : 2021-10-30 21:13:19
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> ts(N, 0);
    std::vector<int> cs(N, -1);
    std::iota(ts.begin(), ts.end(), 0);
    for (int i = 0; i < Q; i++) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 1) {
            int x, y;
            std::cin >> x >> y;
            x--, y--;
            ts[y] = x;
            cs[x] = y;
        } else if (cmd == 2) {
            int x, y;
            std::cin >> x >> y;
            x--, y--;
            ts[y] = y;
            cs[x] = -1;
        } else {
            int x;
            std::cin >> x;
            x--;
            int cnt = 1;
            int idx = x;
            while (cs[idx] != -1) {
                idx = cs[idx];
                cnt++;
            }
            while (ts[x] != x) {
                x = ts[x];
                cnt++;
            }
            std::cout << cnt << " ";
            while (cs[x] != -1) {
                std::cout << x + 1 << " ";
                x = cs[x];
            }
            std::cout << x + 1 << std::endl;
        }
    }
}
