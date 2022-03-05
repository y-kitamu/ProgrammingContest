/*
 * e.cpp
 *
 * Create Date : 2022-03-05 21:49:44
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
    long long int MOD = 998244353;
    int T;
    std::cin >> T;

    std::vector<int> ans(T);
    for (int j = 0; j < T; j++) {
        int N;
        std::string S;
        std::cin >> N >> S;

        long long int mid = (N + 1) / 2;
        long long int all = mod_pow(26, mid, MOD);

        for (int i = 0; i < mid; i++) {
            long long int res = 25 - (int)(S[i] - 'A');
            long long int no = (res * mod_pow(26, mid - i - 1, MOD)) % MOD;
            all = (all - no + MOD) % MOD;
        }

        long long int offset = N % 2;
        for (int i = 0; i < mid; i++) {
            if (S[mid + i - offset] > S[mid - i - 1]) {
                break;
            }
            if (S[mid + i - offset] < S[mid - i - 1]) {
                all = (all - 1 + MOD) % MOD;
                break;
            }
        }
        ans[j] = all;
    }
    for (auto& val : ans) {
        std::cout << val << std::endl;
    }
}
