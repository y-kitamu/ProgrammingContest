/*
 * d.cpp
 *
 * Create Date : 2021-07-31 21:12:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


using ll = long long int;

int main() {
    int Q;
    std::cin >> Q;

    std::priority_queue<ll, std::vector<ll>, decltype(std::greater<ll>())> que{std::greater<ll>()};
    ll offset = 0;
    for (int i = 0; i < Q; i++) {
        int cmd;
        std::cin >> cmd;
        if (cmd == 3) {
            ll top = que.top();
            que.pop();
            std::cout << top + offset << std::endl;
        } else {
            ll x;
            std::cin >> x;
            if (cmd == 1) {
                que.push(x - offset);
            } else if (cmd == 2) {
                offset += x;
            }
        }
    }
}
