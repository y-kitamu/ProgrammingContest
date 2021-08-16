/*
 * c.cpp
 *
 * Create Date : 2021-08-16 20:59:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

int main() {
    int R, C, K, N;
    std::cin >> R >> C >> K;
    std::cin >> N;

    std::vector<int> rs(N), cs(N);
    std::vector<int> cntr(R, 0), cntc(C, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> rs[i] >> cs[i];
        rs[i]--, cs[i]--;
        cntr[rs[i]]++;
        cntc[cs[i]]++;
    }

    std::vector<int> nr(2e5, 0), nc(2e5, 0);
    for (int i = 0; i < R; i++) {
        nr[cntr[i]]++;
    }
    for (int i = 0; i < C; i++) {
        nc[cntc[i]]++;
    }

    long long int sum = 0;
    for (int i = 0; i <= K; i++) {
        sum += nr[i] * nc[K - i];
    }

    for (int i = 0; i < N; i++) {
        if (cntr[rs[i]] + cntc[cs[i]] == K) {
            sum--;
        }
        if (cntr[rs[i]] + cntc[cs[i]] == K + 1) {
            sum++;
        }
    }
    std::cout << sum << std::endl;
}
