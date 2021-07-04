/*
 * c.cpp
 *
 * Create Date : 2021-07-04 11:40:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int countGoodNumbers(long long n) {
        long long int even = (n + 1) / 2;
        long long int odd = n - even;
        long long int MOD = 1e9 + 7;

        return mod_pow(5, even, MOD) * mod_pow(4, odd, MOD) % MOD;
    }

    long long int mod_pow(long long int n, long long int r, long long int MOD) {
        long long int ans = 1;
        long long int pow = n;
        while (r > 0) {
            if (r & 1) {
                ans = (ans * pow) % MOD;
            }
            pow = (pow * pow) % MOD;
            r >>= 1;
        }
        return ans;
    }
};


int main() {}
