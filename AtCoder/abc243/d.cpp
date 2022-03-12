/*
 * d.cpp
 *
 * Create Date : 2022-03-12 21:14:07
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long N, X;
    std::string S;
    std::cin >> N >> X;
    std::cin >> S;

    long long ans = X;
    std::vector<char> path(N);
    int idx = 0;
    for (auto& c : S) {
        if (c == 'U') {
            if (idx == 0) {
                ans /= 2;
            } else {
                idx--;
            }
        } else {
            path[idx++] = c;
        }
    }

    for (int i = 0; i < idx; i++) {
        auto c = path[i];
        if (c == 'U') {
            ans /= 2ll;
        } else if (c == 'R') {
            ans = ans * 2ll + 1ll;
        } else if (c == 'L') {
            ans = ans * 2ll;
        }
    }

    std::cout << ans << std::endl;
}
