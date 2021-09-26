/*
 * e.cpp
 *
 * Create Date : 2021-09-26 21:18:52
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, D;
    std::cin >> N >> D;

    long long int MOD = 998244353;
    std::vector<long long int> pows(std::max(N, D) + 1, 1);
    std::vector<long long int> sums(std::max(N, D) + 1, 0);
    sums[0] = 1;
    for (int i = 0; i < N; i++) {
        pows[i + 1] = pows[i] * 2 % MOD;
        sums[i + 1] = (sums[i] + pows[i]) % MOD;
    }

    // for (auto& val : pows) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;
    // for (auto& val : sums) {
    //     std::cout << val << " ";
    // }
    // std::cout << std::endl;

    long long int ans = 0;
    for (int i = 0; i < N; i++) {
        long long int cnt = 0;
        if (i + D < N) {
            cnt += pows[D];
        }
        if (i > 0) {
            int max_idx = D - std::max(1, (D - N + i + 2) / 2);
            int min_idx = D - std::min(D, i);
            // std::cout << min_idx << " , " << max_idx << std::endl;
            cnt += sums[max_idx];
            if (min_idx > 0) {
                cnt -= sums[min_idx - 1];
            }
        }
        // std::cout << cnt << std::endl;
        cnt = (cnt * pows[i]) % MOD;
        // std::cout << "i = " << i << " , cnt = " << cnt << std::endl;
        ans = (ans + cnt) % MOD;
    }

    std::cout << ans << std::endl;
}
