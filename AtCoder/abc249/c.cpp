/*
 * c.cpp
 *
 * Create Date : 2022-04-23 21:07:59
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> cnts(N, std::vector<int>(26, 0));
    for (int i = 0; i < N; i++) {
        std::string S;
        std::cin >> S;
        for (auto& c : S) {
            cnts[i][c - 'a']++;
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << N); i++) {
        int max = 0;
        std::vector<int> cnt(26, 0);
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                for (int k = 0; k < 26; k++) {
                    cnt[k] += cnts[j][k];
                }
            }
        }
        for (int k = 0; k < 26; k++) {
            if (cnt[k] == K) {
                max++;
            }
        }
        ans = std::max(ans, max);
    }
    std::cout << ans << std::endl;
}
