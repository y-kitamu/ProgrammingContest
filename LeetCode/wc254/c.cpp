/*
 * c.cpp
 *
 * Create Date : 2021-08-15 11:49:10
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
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

    int minNonZeroProduct(int p) {
        long long int mod = 1e9 + 7;
        long long int n = 1ll << p;
        long long int ans = mod_pow((n - 2) % mod, n / 2 - 1, mod);
        ans = (ans * ((n - 1) % mod)) % mod;
        return ans;
    }
};


int main() {}
