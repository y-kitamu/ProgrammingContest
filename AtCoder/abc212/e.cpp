/*
 * e.cpp
 *
 * Create Date : 2021-07-31 21:20:38
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

long long int mod_pow(long long int n, long long int r, long long int MOD) {
    long long int ans = 1;
    long long int pow = n;
    while (r > 0) {
        if (r & 1) {
            n = (pow * n) % MOD;
        }
        pow = (pow * pow) % MOD;
        r >>= 1;
    }
    return ans;
}


int main() {
    long long int MOD = 998244353;
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;

        ll[u].emplace_back(v);
        ll[v].emplace_back(u);
    }

    std::vector<long long int> prev(N, 1), cur(N, 1);
    std::vector<long long int> continu(K);

    for (int j = 0; j < K; j++) {
        long long int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (auto next : ll[i]) {
                cur[next] += prev[i];
                cnt++;
            }
        }
        continu[j] = cnt;
    }
}
