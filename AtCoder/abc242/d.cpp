/*
 * d.cpp
 *
 * Create Date : 2022-03-05 21:13:57
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    std::string S;
    int Q;
    std::cin >> S >> Q;

    std::vector<char> ans(Q);
    for (int i = 0; i < Q; i++) {
        long long int t, k;
        std::cin >> t >> k;
        k--;

        long long int offset;
        if (t < 60) {
            long long int idx = k / (1ll << t);
            k = k % (1ll << t);
            offset = (long long int)(S[idx] - 'A');
        } else {
            offset = (long long int)((t - 60 + (int)(S[0] - 'A')) % 3);
            t = 60;
        }
        while (t > 0) {
            if (k & (1ll << (t - 1))) {
                offset--;
            } else {
                offset++;
            }
            t--;
        }
        ans[i] = (char)('A' + (offset % 3 + 3) % 3);
    }
    for (auto& val : ans) {
        std::cout << val << std::endl;
    }
}
