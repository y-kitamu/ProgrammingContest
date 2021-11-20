/*
 * e.cpp
 *
 * Create Date : 2021-11-20 21:39:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long int mod_pow(long long int n, long long int r, long long int mod) {
    long long int ans = 1;
    long long int pow = n % mod;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return (ans + mod) % mod;
}

int main() {
    long long int MOD = 998244353;
    long long int N, K, M;
    std::cin >> N >> K >> M;

    if (M % MOD == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long int kn = mod_pow(K, N, MOD - 1);
    long long int ans = mod_pow(M % MOD, kn, MOD);
    std::cout << ans % MOD << std::endl;
}
