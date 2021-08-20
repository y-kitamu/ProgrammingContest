/*
 * c.cpp
 *
 * Create Date : 2021-08-20 21:58:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long int mod_pow(long long int n, long long int r, long long int mod) {
    long long int ans = 1;
    long long int pow = n;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return ans;
}

int main() {
    long long int mod = 1e9 + 7;
    long long int N;
    std::cin >> N;

    long long int ans = mod_pow(10, N, mod) - 2 * mod_pow(9, N, mod) % mod + mod_pow(8, N, mod);
    std::cout << (ans % mod + mod) % mod << std::endl;
}
