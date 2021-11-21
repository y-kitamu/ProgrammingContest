/*
 * c.cpp
 *
 * Create Date : 2021-11-21 21:44:27
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    N *= 2;
    std::vector<int> cnts(7, 0);
    for (int i = 0; i < 7; i++) {
        int sq = std::sqrt(N);
        if ((sq + 1) * sq <= N) {
            cnts[i] = sq + 1;
            N -= (sq + 1) * sq;
        } else {
            cnts[i] = sq;
            N -= sq * (sq - 1);
        }
        if (N == 0) {
            break;
        }
    }

    int mod = 0;
    int mod_scale = 1;
    std::vector<int> ans;
    for (int k = 0; k < cnts[0] - 1; k++) {
        ans.emplace_back(7);
        mod_scale = mod_scale * 10 % 7;
    }
    for (int i = 1; i < 7; i++) {
        if (cnts[i] == 0) {
            continue;
        }
        for (int k = 1; k <= 9; k++) {
            if (mod + mod_scale * k % 7 == i + 1) {
                ans.emplace_back(k);
                mod = i + 1;
                mod_scale = mod_scale * 10 % 7;
                break;
            }
        }
        for (int j = 0; j < cnts[i] - 1; j++) {
            ans.emplace_back(7);
            mod_scale = mod_scale * 10 % 7;
        }
    }

    int len = ans.size();
    for (int i = 0; i < len; i++) {
        std::cout << ans[len - i - 1];
    }
    std::cout << std::endl;
}
